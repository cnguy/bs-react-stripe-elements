let component = ReasonReact.statelessComponent("PaymentRequestButtonElement");

[@bs.deriving abstract]
type paymentRequestButtonType = {
  theme: option(string),
  height: option(string),
  [@bs.as "type"]
  type_: option(string),
};

[@bs.deriving abstract]
type style = {paymentRequestButton: option(paymentRequestButtonType)};

let makePaymentRequestButton = (~theme=?, ~height=?, ~type_=?, ()) =>
  paymentRequestButtonType(~theme, ~height, ~type_);
let makeStyle = (~paymentRequestButton=?, ()) =>
  style(~paymentRequestButton);

[@bs.deriving abstract]
type jsProps = {
  paymentRequest: option(StripeElements_Inject.paymentRequest),
  style: option(style),
  className: option(string),
};

type type_ =
  | Default
  | Donate
  | Buy;

type theme =
  | Dark
  | Light
  | LightOutline;

type paymentRequestButtonStyle = {
  type_,
  theme,
  height: string,
};

let paymentRequestButtonStyleToJs = style =>
  makePaymentRequestButton(
    ~type_=
      switch (style.type_) {
      | Default => "default"
      | Donate => "donate"
      | Buy => "buy"
      },
    ~theme=
      switch (style.theme) {
      | Dark => "dark"
      | Light => "light"
      | LightOutline => "light-outline"
      },
    ~height=style.height,
    (),
  );

let make =
    (
      ~paymentRequest: option(StripeElements_Inject.paymentRequest),
      ~type_=Default,
      ~theme=Dark,
      ~height="40px",
      ~className: option(string)=?,
      _children,
    ) => {
  let paymentRequestButtonStyle = {type_, theme, height};
  let style =
    Some(
      makeStyle(
        ~paymentRequestButton=
          paymentRequestButtonStyleToJs(paymentRequestButtonStyle),
        (),
      ),
    );
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.paymentRequestButtonElementGet(
        StripeElements_Components.default,
      ),
    ~props=jsProps(~paymentRequest, ~style, ~className),
    (),
  );
};