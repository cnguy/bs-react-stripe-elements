[@bs.module "react-stripe-elements/lib/components/Elements"]
external elements: ReasonReact.reactClass = "default";

let make = (children: ReasonReact.reactElement) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=elements,
    ~props=Js.Obj.empty(),
    children,
  );