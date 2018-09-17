[@bs.deriving abstract]
type placeholderType = {color: option(string)};

[@bs.deriving abstract]
type baseType = {
  color: option(string),
  lineHeight: option(string),
  fontFamily: option(string),
  fontSmoothing: option(string),
  fontSize: option(string),
  [@bs.as "::placeholder"]
  placeholder: option(placeholderType),
};

[@bs.deriving abstract]
type invalidType = {
  color: option(string),
  iconColor: option(string),
};

[@bs.deriving abstract]
type style = {
  base: option(baseType),
  invalid: option(invalidType),
};

let makeBase =
    (
      ~color=?,
      ~lineHeight=?,
      ~fontFamily=?,
      ~fontSmoothing=?,
      ~fontSize=?,
      ~placeholder=?,
      (),
    ) =>
  baseType(
    ~color,
    ~lineHeight,
    ~fontFamily,
    ~fontSmoothing,
    ~fontSize,
    ~placeholder,
  );
let makePlaceholder = (~color=?, ()) => placeholderType(~color);
let makeInvalid = (~color=?, ~iconColor=?, ()) =>
  invalidType(~color, ~iconColor);
let makeStyle = (~base=?, ~invalid=?, ()) => style(~base, ~invalid);

[@bs.deriving abstract]
type jsProps = {style: option(style)};

let component = ReasonReact.statelessComponent("CardElement");
let make = (~style: option(style)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.cardElementGet(
        StripeElements_Components.default,
      ),
    ~props=jsProps(~style),
    children,
  );