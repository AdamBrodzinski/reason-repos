[%bs.raw {| import('./App.css') |}];

let text = ReasonReact.string;

type action =
  | Loaded(array(RepoData.repo));

type state = {data: option(array(RepoData.repo))};

let make = _children => {
  ...ReasonReact.reducerComponent("App"),
  didMount: self => {
    let _ =
      Js.Global.setTimeout(
        () => {
          let repos = RepoData.getRepos();
          self.send(Loaded(repos));
        },
        900,
      );
    ();
  },
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