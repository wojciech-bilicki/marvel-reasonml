let component = ReasonReact.statelessComponent("Home");

let str = ReasonReact.stringToElement;

let make = (_children) => {...component, render: (_self) => <div> (str("Home")) </div>};