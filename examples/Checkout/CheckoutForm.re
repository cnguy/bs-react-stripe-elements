module CardForm = {
  let component = ReasonReact.statelessComponent("CardForm");

  let make = (~stripe, _children) => {
    let handleSubmit = event: unit => {
      event->ReactEvent.Synthetic.preventDefault;
      let createTokenArgs = Some({"name": "Jenny Rosen"});
      Js.Promise.(
        stripe->(StripeElements_Inject.createToken(createTokenArgs))
        |> then_(response => Js.log(response) |> resolve)
      )
      |> ignore;
      ();
    };
    {
      ...component,
      render: _self =>
        StripeElements.(
          <form onSubmit=handleSubmit>
            <label>
              {ReasonReact.string("Card details")}
              <CardElement />
            </label>
            <button> {ReasonReact.string("Pay")} </button>
          </form>
        ),
    };
  };
};

module SplitForm = {
  let component = ReasonReact.statelessComponent("SplitForm");

  let make = (~stripe, _children) => {
    let handleSubmit = event: unit => {
      event->ReactEvent.Synthetic.preventDefault;
      let createTokenArgs = Some({"name": "Jenny Rosen"});
      Js.Promise.(
        stripe->(StripeElements_Inject.createToken(createTokenArgs))
        |> then_(response => Js.log(response) |> resolve)
      )
      |> ignore;
      ();
    };
    {
      ...component,
      render: _self =>
        StripeElements.(
          <form onSubmit=handleSubmit>
            <label>
              {ReasonReact.string("Card number")}
              <CardNumberElement />
            </label>
            <label>
              {ReasonReact.string("Expiration date")}
              <CardExpiryElement />
            </label>
            <label> {ReasonReact.string("CVC")} <CardCVCElement /> </label>
            <label>
              {ReasonReact.string("Postal code")}
              <PostalCodeElement />
            </label>
            <button> {ReasonReact.string("Pay")} </button>
          </form>
        ),
    };
  };
};

module PaymentRequestForm = {
  type state = {
    canMakePayment: bool,
    paymentRequest: option(StripeElements_Inject.paymentRequest),
  };

  type action =
    | SetState(bool, StripeElements_Inject.paymentRequest);

  let component = ReasonReact.reducerComponent("PaymentRequestForm");

  let make = (~stripe, _children) => {
    ...component,
    initialState: () => {canMakePayment: false, paymentRequest: None},
    didMount: self => {
      let paymentRequest =
        stripe
        ->(
            StripeElements_Inject.paymentRequestFn({
              "country": "US",
              "currency": "usd",
              "total": {
                "label": "Demo total",
                "amount": 1000.,
              },
            })
          );
      paymentRequest
      ->(
          StripeElements_Inject.on("token", data => {
            Js.log("Received Stripe token: " ++ data##token);
            Js.log("Received customer information: " ++ data##data);
            StripeElements_Inject.complete(data, "success");
            ();
          })
        );
      Js.Promise.(
        StripeElements_Inject.canMakePayment(paymentRequest)
        |> then_(result =>
             self.send(SetState(!(!result), paymentRequest)) |> resolve
           )
      )
      |> ignore;
    },
    reducer: (action, state) =>
      switch (action) {
      | SetState(canMakePayment, paymentRequest) =>
        ReasonReact.Update({
          canMakePayment,
          paymentRequest: Some(paymentRequest),
        })
      },
    render: self =>
      self.state.canMakePayment ?
        StripeElements.(
          <PaymentRequestButtonElement
            paymentRequest={self.state.paymentRequest}
            className="PaymentRequestButton"
            style={
              StripeElements.PaymentRequestButtonElement.makeStyle(
                ~paymentRequestButton=
                  StripeElements.PaymentRequestButtonElement.makePaymentRequestButton(
                    ~theme="dark",
                    ~height="64px",
                    ~type_="donate",
                    (),
                  ),
                (),
              )
            }
          />
        ) :
        ReasonReact.null,
  };
};

module IbanForm = {
  let component = ReasonReact.statelessComponent("IbanForm");

  let make = (~stripe, _children) => {
    let handleSubmit = event: unit => {
      event->ReactEvent.Synthetic.preventDefault;
      let createSourceArgs = {
        "type": "sepa_debit",
        "currency": "eur",
        "owner": {
          "name": event->ReactEvent.Form.target##name##value,
          "email": event->ReactEvent.Form.target##email##value,
        },
        "mandate": {
          "notification_method": "email",
        },
      };
      Js.Promise.(
        stripe->(StripeElements_Inject.createSource(createSourceArgs))
        |> then_(response => Js.log(response) |> resolve)
      )
      |> ignore;
      ();
    };
    {
      ...component,
      render: _self =>
        StripeElements.(
          <form onSubmit=handleSubmit>
            <label>
              {ReasonReact.string("Name")}
              <input
                name="name"
                type_="text"
                placeholder="Jane Doe"
                required=true
              />
            </label>
            <label>
              {ReasonReact.string("Email")}
              <input
                name="email"
                type_="email"
                placeholder="jane.doe@example.com"
                required=true
              />
            </label>
            <label>
              {ReasonReact.string("IBAN")}
              <IbanElement supportedCountries={Array.of_list(["SEPA"])} />
            </label>
            <button> {ReasonReact.string("Pay")} </button>
          </form>
        ),
    };
  };
};

module IdealBankForm = {
  let component = ReasonReact.statelessComponent("IdealBankForm");

  let make = (~stripe, _children) => {
    let handleSubmit = event: unit => {
      event->ReactEvent.Synthetic.preventDefault;
      let createSourceArgs = {
        "type": "ideal",
        "amount": 1000,
        "currency": "eur",
        "redirect": {
          "return_url": "https://example.com",
        },
      };
      Js.Promise.(
        stripe->(StripeElements_Inject.createSource(createSourceArgs))
        |> then_(response => Js.log(response) |> resolve)
      )
      |> ignore;
      ();
    };
    {
      ...component,
      render: _self =>
        StripeElements.(
          <form onSubmit=handleSubmit>
            <label>
              {ReasonReact.string("Name")}
              <input
                name="name"
                type_="text"
                placeholder="Jane Doe"
                required=true
              />
            </label>
            <label>
              {ReasonReact.string("iDEAL Bank")}
              <IdealBankElement />
            </label>
            <button> {ReasonReact.string("Pay")} </button>
          </form>
        ),
    };
  };
};

let component = ReasonReact.statelessComponent("CheckoutForm");

let make = _children => {
  ...component,
  render: _self =>
    StripeElements.(
      <div className="Checkout">
        <h1> {ReasonReact.string("Available elements")} </h1>
        <Elements>
          ...<Inject> ...{(~stripe) => <CardForm stripe />} </Inject>
        </Elements>
        <Elements>
          ...<Inject> ...{(~stripe) => <SplitForm stripe />} </Inject>
        </Elements>
        <Elements>
          ...<Inject> ...{(~stripe) => <IbanForm stripe />} </Inject>
        </Elements>
        <Elements>
          ...<Inject>
               ...{(~stripe) => <PaymentRequestForm stripe />}
             </Inject>
        </Elements>
        <Elements>
          ...<Inject> ...{(~stripe) => <IdealBankForm stripe />} </Inject>
        </Elements>
      </div>
    ),
};