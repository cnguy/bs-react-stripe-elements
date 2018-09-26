let component = ReasonReact.statelessComponent("CardExpiryElement");

let make = _children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.cardExpiryElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    (),
  );