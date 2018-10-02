let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      StripeElements.(
        <StripeProvider apiKey="pk_abcdefghijklmnoprstuvwxyz">
          ...<CheckoutForm />
        </StripeProvider>
      )
    </div>,
};