type query;

type wrapper = (ReasonReact.reactClass => ReasonReact.reactClass) [@bs];

type gql = (string => query) [@bs];
type graphql = (query => wrapper) [@bs];
