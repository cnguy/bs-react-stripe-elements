type supportedCountries = array(string); /* constrain it? */

[@bs.deriving abstract]
type jsProps = {
  supportedCountries,
  placeholderCountry: option(string),
};

let component = ReasonReact.statelessComponent("IbanElement");

let make = (~supportedCountries, ~placeholderCountry=?, _children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=
      StripeElements_Components.ibanElementGet(
        StripeElements_Components.default,
      ),
    ~props=jsProps(~supportedCountries, ~placeholderCountry),
    (),
  );