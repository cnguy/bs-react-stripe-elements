type hoc = ReasonReact.reactClass => ReasonReact.reactClass;

[@bs.module "react-stripe-elements/lib/components/inject"]
external inject: hoc = "default";

type createTokenArgs = {. "name": string};

type createSourceArgs('a) = {.. "type": string} as 'a;

[@bs.deriving abstract]
type stripe;
[@bs.deriving.abstract]
type createTokenResponse = {token: string};
[@bs.send]
external createToken:
  (stripe, option(createTokenArgs)) => Js.Promise.t(createTokenResponse) =
  "createToken";
type createSourceResponse = {token: string};
[@bs.send]
external createSource:
  (stripe, createSourceArgs('a)) => Js.Promise.t(createSourceResponse) =
  "createSource";

type paymentRequestT = {on: (string, string)};

type totalType = {
  .
  "label": string,
  "amount": float,
};

type paymentRequestArgs = {
  .
  "country": string,
  "currency": string,
  "total": totalType,
};

[@bs.deriving abstract]
type paymentRequest;

[@bs.send]
external paymentRequestFn: (stripe, paymentRequestArgs) => paymentRequest =
  "paymentRequest";

type onReturn = {
  .
  "token": string,
  "data": string,
};

[@bs.send]
external on: (paymentRequest, string, onReturn => unit) => unit = "on";
[@bs.send]
external canMakePayment: paymentRequest => Js.Promise.t(bool) =
  "canMakePayment";
[@bs.send]
external complete: (onReturn, string) => Js.Promise.t(unit) = "complete";

type children = (~stripe: stripe) => ReasonReact.reactElement;

let component = ReasonReact.statelessComponent("Inject");

let make' = (~stripe: stripe, children: children) => {
  ...component,
  render: _self => children(~stripe),
};

let jsComponent =
  ReasonReact.wrapReasonForJs(
    ~component,
    (
      props: {
        .
        "stripe": stripe,
        "children": children,
      },
    ) =>
    make'(~stripe=props##stripe, props##children)
  );

let enhanced = inject(jsComponent);

let make = (children: children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=enhanced,
    ~props=Js.Obj.empty(),
    children,
  );