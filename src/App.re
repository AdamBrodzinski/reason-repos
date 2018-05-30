[%bs.raw {| import('./App.css') |}];

let text = ReasonReact.string;

let repos: array(RepoData.repo) = [|
  {full_name: "facebook/reason", stargazers_count: 5742, url: "foo"},
  {full_name: "jaredpalmer/razzle", stargazers_count: 4029, url: "foo"},
|];

type action =
  | Loaded(array(RepoData.repo));

type state = {data: option(array(RepoData.repo))};

let make = _children => {
  ...ReasonReact.reducerComponent("App"),
  initialState: () => {data: None},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(repos) => ReasonReact.Update({data: Some(repos)})
    },
  render: self =>
    <div className="App">
      <h1> (text("Reason Project")) </h1>
      (
        switch (self.state.data) {
        | Some(mrepos) =>
          ReasonReact.array(
            Array.mapi(
              (i, repo) => <RepoItem key=(string_of_int(i)) repo />,
              mrepos,
            ),
          )
        | None => <div className="loading"> (text("Loading...")) </div>
        }
      )
    </div>,
};