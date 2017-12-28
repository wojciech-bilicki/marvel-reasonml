module History = {
  type h;
  [@bs.send] external goBack : h => unit = "";
  [@bs.send] external goForward : h => unit = "";
  [@bs.send] external go : (h, ~jumps: int) => unit = "";
  [@bs.get] external length : h => int = "";
  [@bs.get] external location : h => string = "";
  module Location = {
    type l;
    [@bs.get] external pathname : l => string = "";
    [@bs.get] external search : l => string = "";
    [@bs.get] external hash : l => string = "";
  };
};