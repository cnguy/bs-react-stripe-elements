let component = ReasonReact.statelessComponent("IdealBankElement");

let make = _children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.idealBankElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    (),
  );