let component = ReasonReact.statelessComponent("CardCVCElement");

let make = _children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.cardCVCElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    (),
  );