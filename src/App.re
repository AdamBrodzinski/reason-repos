[%bs.raw {| import('./App.css') |}];
open Js.Promise;

let text = ReasonReact.string;

type action =
  | Loaded(array(RepoData.repo));

type state = {data: option(array(RepoData.repo))};

let make = _children => {
  ...ReasonReact.reducerComponent("App"),
  initialState: () => {data: None},
  didMount: self => {
    RepoData.getRepos()
    |> then_(repoData => {
         self.send(Loaded(repoData));
         resolve();
       })
    |> catch(_err => {
         [%bs.raw {| alert("Error loading repos") |}] |> ignore;
         resolve();
       })
    |> ignore;
    ();
  },
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(repos) => ReasonReact.Update({data: Some(repos)})
    },
  render: self =>
    <div className="App">
      <h1> (text("Reason Project")) </h1>
      (
        switch (self.state.data) {
        | Some(repos) =>
          ReasonReact.array(
            Array.mapi(
              (i, repo) => <RepoItem key=(string_of_int(i)) repo />,
              repos,
            ),
          )
        | None => <div className="loading"> (text("Loading...")) </div>
        }
      )
    </div>,
};