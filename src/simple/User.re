open GraphQLTypes;

external gql:gql = "graphql-tag" [@@bs.module];
external graphql:graphql = "graphql" [@@bs.module "react-apollo"];

type state = {sayHo: string};

type action =
  Click;

let component = ReasonReact.reducerComponent "Greeting";

let user ::data _children => {
  ...component,
  initialState: fun () => { sayHo: "HO"},
  reducer: fun action state =>
    switch action {
    |  Click => ReasonReact.Update {sayHo: state.sayHo == "HO" ? "HI" : "HO"}
    },
  render: fun {state, reduce} => {
    let name = if(data##loading) {
      ""
    } else{
      data##getUser##name
    };

    <div
      onClick=(reduce (fun _event => Click))
    >
      (ReasonReact.stringToElement (state.sayHo ^ " "))
      (ReasonReact.stringToElement (name))
    </div>
  }
};

/* Reason -> JS */
let userJs = ReasonReact.wrapReasonForJs ::component (fun jsProps => {
  user data::jsProps##data [||];
});

let query =
  gql {|
    query getUser {
      getUser {
        name
      }
    }
  |} [@bs];

let graphqlQuery = graphql query [@bs];
let userWithQuery: ReasonReact.reactClass = graphqlQuery userJs [@bs];

/* JS -> Reason */
let make children =>
  ReasonReact.wrapJsForReason
    reactClass::userWithQuery
    props::(Js.Obj.empty ())
    children;
