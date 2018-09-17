[@bs.module "react-stripe-elements/lib/components/Provider"]
external provider: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {apiKey: string};

let make = (~apiKey: string, children: ReasonReact.reactElement) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=provider,
    ~props=jsProps(~apiKey),
    children,
  );