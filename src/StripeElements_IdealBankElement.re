let component = ReasonReact.statelessComponent("IdealBankElement");
let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.idealBankElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    children,
  );