let component = ReasonReact.statelessComponent "App";

let make = fun _children => {
  ...component,
  render: fun _self => {
    <ApolloProvider client=ApolloClient.instance>
      <User/>
    </ApolloProvider>
  }
};