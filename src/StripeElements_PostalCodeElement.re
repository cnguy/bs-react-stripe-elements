let component = ReasonReact.statelessComponent("PostalCodeElement");
let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.postalCodeElementGet(
        StripeElements_Components.default,
      ),
    ~props=Js.Obj.empty(),
    children,
  );