[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external withKnobs : Main.decorator =
  "";

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extText : (string, Js.null_undefined(string)) => string =
  "text";

let text = (~label: string, ~defaultValue: option(string)=?, ()) =>
  extText(label, Js.Nullable.from_opt(defaultValue));

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extBoolean : (string, Js.boolean) => Js.boolean =
  "boolean";

let boolean = (~label: string, ~defaultValue=Js.false_, ()) =>
  Js.to_bool(extBoolean(label, defaultValue));

type jsRangeConfig = {
  .
  "range": Js.boolean, "min": float, "max": float, "step": float
};

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extNumber : (string, float, Js.null_undefined(jsRangeConfig)) => float =
  "number";

type rangeConfig = {
  min: float,
  max: float,
  step: float
};

let number =
    (
      ~label: string,
      ~defaultValue=0.,
      ~rangeConfiguration: option(rangeConfig)=?,
      ()
    )
    : float =>
  switch rangeConfiguration {
  | None => extNumber(label, defaultValue, Js.Nullable.undefined)
  | Some(c) =>
    let config = {
      "range": Js.true_,
      "min": c.min,
      "max": c.max,
      "step": c.step
    };
    extNumber(label, defaultValue, Js.Nullable.return(config))
  };

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extColor : (string, Js.null_undefined(string)) => string =
  "color";

let color = (~label: string, ~defaultValue: option(string)=?, ()) =>
  extColor(label, Js.Nullable.from_opt(defaultValue));

type selectConfig('a) = 'a;

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extSelect :
  (string, selectConfig('a), Js.null_undefined(string)) => string =
  "select";

let select =
    (
      ~label: string,
      ~options: selectConfig('a),
      ~defaultValue: option(string)=?,
      ()
    ) =>
  extSelect(label, options, Js.Nullable.from_opt(defaultValue));

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extDate : (string, Js.null_undefined(Js_date.t)) => string =
  "date";

let date = (~label: string, ~defaultValue: option(Js_date.t)=?, ()) =>
  extDate(label, Js.Nullable.from_opt(defaultValue));

[@bs.val] [@bs.module "@storybook/addon-knobs/react"]
external extButton : (string, ReactEventRe.Mouse.t => unit) => unit =
  "button";

let button = (~label: string, ~handler: ReactEventRe.Mouse.t => unit, ()) =>
  extButton(label, handler);
