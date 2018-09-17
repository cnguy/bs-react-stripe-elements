[@bs.deriving abstract]
type default = {
  [@bs.as "CardElement"]
  cardElement: ReasonReact.reactClass,
  [@bs.as "CardNumberElement"]
  cardNumberElement: ReasonReact.reactClass,
  [@bs.as "CardExpiryElement"]
  cardExpiryElement: ReasonReact.reactClass,
  [@bs.as "CardCVCElement"]
  cardCVCElement: ReasonReact.reactClass,
  [@bs.as "PostalCodeElement"]
  postalCodeElement: ReasonReact.reactClass,
  [@bs.as "PaymentRequestButtonElement"]
  paymentRequestButtonElement: ReasonReact.reactClass,
  [@bs.as "IbanElement"]
  ibanElement: ReasonReact.reactClass,
  [@bs.as "IdealBankElement"]
  idealBankElement: ReasonReact.reactClass,
};

[@bs.module] external default: default = "react-stripe-elements/lib/index";