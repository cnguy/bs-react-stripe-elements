let component = ReasonReact.statelessComponent("CardExpiryElement");
let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.cardExpiryElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    children,
  );