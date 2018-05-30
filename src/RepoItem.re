[%bs.raw {| require("./RepoItem.css") |}];

let text = ReasonReact.string;

let make = (~repo: RepoData.repo, _children) => {
  ...ReasonReact.statelessComponent("RepoItem"),
  render: _self =>
    <div className="RepoItem">
      <a href=repo.url target="_target">
        <h2> (text(repo.full_name)) </h2>
        <span className="star-count">
          (text((repo.stargazers_count |> string_of_int) ++ " Stars"))
        </span>
      </a>
    </div>,
};