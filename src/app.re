[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

open ReactRouter;

let renderHome = () => <Home />;

let renderDetails = () => <Details />;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <BrowserRouter>
      <div> <TopBar />
      <Switch>
        <Route path="/" exact=true component=renderHome /> 
        <Route path="/details" exact=true component=renderDetails />
      </Switch>
      </div>
    </BrowserRouter>
};