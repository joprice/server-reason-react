let _ = [%browser_only Webapi.Dom.getElementById("foo")];

let%browser_only logTest = () => [%mel.raw
  {|
    (function() {
   var socketUrl = "ws://" + location.host + "/_livereload";
   var s = new WebSocket(socketUrl);

   s.onopen = function(even) {
     console.debug("Live reload: WebSocket connection open");
   };

   s.onclose = function(even) {
     console.debug("Live reload: WebSocket connection closed");

     var retryIntervalMs = 500;

     function reload() {
       s2 = new WebSocket(socketUrl);

       s2.onerror = function(event) {
         setTimeout(reload, retryIntervalMs);
       };

       s2.onopen = function(event) {
         location.reload();
       };
     };

     reload();
   };

   s.onerror = function(event) {
     console.debug("Live reload: WebSocket error:", event);
   };
  })()
  |}
];

let%browser_only loadInitialText = () => {
  setHtmlFetchState(Loading);
};

let%browser_only loadInitialText = argument1 => {
  setHtmlFetchState(Loading);
};

let%browser_only loadInitialText = (argument1, argument2) => {
  setHtmlFetchState(Loading);
};

let make = () => {
  let _ = [%browser_only Webapi.Dom.getElementById("foo")];

  let%browser_only loadInitialText = () => {
    setHtmlFetchState(Loading);
  };

  let%browser_only loadInitialText = argument1 => {
    setHtmlFetchState(Loading);
  };

  let%browser_only loadInitialText = (argument1, argument2) => {
    setHtmlFetchState(Loading);
  };

  React.createElement("div");
};
