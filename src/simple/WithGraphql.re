
let test = fun config => {
  let test = [];

  let query = fun field => {
    let t = [field];
  };

  fun component => ReasonReact.element (component query::query [||])
};