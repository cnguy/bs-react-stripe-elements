let component = ReasonReact.statelessComponent("CardNumberElement");

let make = _children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.cardNumberElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    (),
  );