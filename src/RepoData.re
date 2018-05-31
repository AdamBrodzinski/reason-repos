type repo = {
  full_name: string,
  stargazers_count: int,
  url: string,
};

let repoUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

let parseRepoItems = (json: Js.Json.t) : repo =>
  Json.Decode.{
    full_name: field("full_name", string, json),
    stargazers_count: field("stargazers_count", int, json),
    url: field("html_url", string, json),
  };

let parseGetResponse = json =>
  Json.Decode.field("items", Json.Decode.array(parseRepoItems), json);

let getRepos = () =>
  Js.Promise.(
    Fetch.fetch(repoUrl)
    |> then_(Fetch.Response.text)
    |> then_(jsonText =>
         parseGetResponse(Js.Json.parseExn(jsonText)) |> resolve
       )
  );