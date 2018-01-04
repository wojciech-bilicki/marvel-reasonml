type hero = {
  id: int,
  name: string,
  true_name: string,
  powers: list(string),
  place_of_birth: string,
  citizenship: string,
  image: string,
  description: option(string),
  comics: list(int)
};

let component = ReasonReact.statelessComponent("HeroCard");

let str = ReasonReact.stringToElement;

let make = (~hero: hero, _children) => {
  ...component,
  render: (_self) => <div> (str("Hero name " ++ hero.name)) </div>
};