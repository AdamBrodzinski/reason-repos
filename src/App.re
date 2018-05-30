[%bs.raw {| import('./App.css') |}];

let text = ReasonReact.string;

let make = _children => {
  ...ReasonReact.statelessComponent("App"),
  render: _self => <div className="Appp"> (text("Hello World")) </div>,
};