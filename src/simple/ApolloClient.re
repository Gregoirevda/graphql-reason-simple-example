type networkInterfaceResult;
type apolloClientResult;
type networkInterface = Js.t {. uri: string};
/*type createNetworkInterface = networkInterface => networkInterfaceResult;*/
type apolloClient = Js.t {. networkInterface: networkInterfaceResult};
/*type apolloClientConstructor = apolloClient => apolloClientResult;*/

external createNetworkInterface: networkInterface => networkInterfaceResult = "createNetworkInterface" [@@bs.module "react-apollo"];
external apolloClient: apolloClient => apolloClientResult = "ApolloClient" [@@bs.new] [@@bs.module "react-apollo"];

let networkInterface = createNetworkInterface {"uri": "http://localhost:3010/graphql"};
let instance = apolloClient { "networkInterface": networkInterface };
