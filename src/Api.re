let parseHeroJson = (json: Js.Json.t) : HeroCard.hero =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
    true_name: json |> field("true_name", string),
    place_of_birth: json |> field("place_of_birth", string),
    description: json |> optional(field("description", string)),
    image: json |> field("image", string),
    citizenship: json |> field("image", string),
    comics: json |> field("comics", list(int)),
    powers: json |> field("powers", list(string))
  };

let parseHeroesJson = (json) => Json.Decode.array(parseHeroJson, json);

let fetchHeroes = () =>
  Js.Promise.(
    Axios.get("http://localhost:8001/api/v1/heroes")
    |> then_((response) => resolve(parseHeroesJson(response##data)))
  );