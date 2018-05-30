[%bs.raw {| import('./App.css') |}];

let text = ReasonReact.string;

let repos: array(RepoData.repo) = [|
  {full_name: "facebook/reason", stargazers_count: 5742, url: "foo"},
  {full_name: "jaredpalmer/razzle", stargazers_count: 4029, url: "foo"},
|];

let make = _children => {
  ...ReasonReact.statelessComponent("App"),
  render: _self =>
    <div className="App">
      <h1> (text("Reason Project")) </h1>
      (
        ReasonReact.array(
          Array.mapi(
            (i, repo) => <RepoItem key=(string_of_int(i)) repo />,
            repos,
          ),
        )
      )
    </div>,
};