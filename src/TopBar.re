[@bs.module] external logo : string = "./assets/Marvel-Logo.png";
let component = ReasonReact.statelessComponent("YoDawgTopBar");

let str = ReasonReact.stringToElement;

let style =
  Css.(
    {
      "header":
        style([
          backgroundColor(rgba(238, 35, 45, 1.0)),
          display(Flex),
          justifyContent(SpaceBetween),
          alignItems(Center)
        ]),
      "title": style([color(white), fontSize(px(36)), fontWeight(Bold)]),
      "logo": style([width(px(200)), height(px(80)), marginLeft(px(32)) ]),
      "search_input_wrapper":style([marginRight(px(32))]),
      "search_input": style([marginRight(px(8))])
    }
  );

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header className=style##header>
      <a href="#"> 
        <img className=style##logo src={logo} />
      </a>
      <span className=style##title> (str("Super Marvel Heroes")) </span>
      <div className=style##search_input_wrapper>
        <input className=style##search_input placeholder="search" />
        <button> (str("Search")) </button>
      </div>
    </header>
};