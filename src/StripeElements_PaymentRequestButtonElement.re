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

let make =
    (
      ~paymentRequest: option(StripeElements_Inject.paymentRequest),
      ~style: option(style)=?,
      ~className: option(string)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.paymentRequestButtonElementGet(
        StripeElements_Components.default,
      ),
    ~props=jsProps(~paymentRequest, ~style, ~className),
    children,
  );