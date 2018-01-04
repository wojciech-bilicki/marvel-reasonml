type state = {heroes: option(array(HeroCard.hero))};

type action =
  | HeroesFetched(array(HeroCard.hero));

let component = ReasonReact.reducerComponent("Home");

let str = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  initialState: () => {heroes: None},
  reducer: (action, _state) =>
    switch action {
    | HeroesFetched(heroes) => ReasonReact.Update({heroes: Some(heroes)})
    },
  didMount: (self) => {
    let handleLoadedHeroes = self.reduce((heroes) => HeroesFetched(heroes));
    Api.fetchHeroes()
    |> Js.Promise.then_(
         (heroes) => {
           handleLoadedHeroes(heroes);
           Js.Promise.resolve()
         }
       )
    |> ignore;
    ReasonReact.NoUpdate
  },
  render: (self) => {
    let heroesComponent = switch (self.state.heroes) {
    | Some(heroes) => ReasonReact.arrayToElement( Array.map((hero:HeroCard.hero) => <HeroCard key=string_of_int(hero.id) hero=hero  />, heroes))
    | None => str("Loading")
    };
    <div> {heroesComponent} </div>
  } 
};