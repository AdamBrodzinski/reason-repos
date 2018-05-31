type repo = {
  full_name: string,
  stargazers_count: int,
  url: string,
};

let getRepos = () : array(repo) => {
  Js.log("fetching");
  [|
    {full_name: "facebook/reason", stargazers_count: 5742, url: "foo"},
    {full_name: "jaredpalmer/razzle", stargazers_count: 4029, url: "foo"},
  |];
};