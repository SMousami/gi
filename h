<HTML>
  <HEAD>
      <TITLE>Hello!  This is an example!</TITLE>
      <script src="https://cdn.jsdelivr.net/npm/vega@5.16.1"></script>
      <script src="https://cdn.jsdelivr.net/npm/vega-lite@4.16.2"></script>
      <script src="https://cdn.jsdelivr.net/npm/vega-embed@6.12.2"></script>
  </HEAD>
  <BODY>
    <h1>This is a header.</h1>
    <p>And, some text.</p>
      <button onclick = "setupViz()">This is a button</button>
      <button onclick = "addNewDatapoint()">Add</button>
     <div id="viz"></div>
      <script>
          var myViz
          var vlSpec = {
    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
    "data": {
              "name":"exampletable",
        "values": [
            {"A": 10, "B": 21, "C": 2},
            {"A": 30, "B": 20, "C": 4},
            {"A": 25, "B": 15, "C": 6},
            {"A": 5, "B": 30, "C": 8}
        ]
    },
    "mark": "circle",
    "encoding": {
        "x": { "field": "A", "type": "quantitative"},
        "y": { "field": "B", "type": "quantitative"},
        "size": { "field": "C", "type": "quantitative"}
    }
}
          function setupViz(){
          myViz = vegaEmbed("#viz", vlSpec);
          }
          function addNewDatapoint(){
          var changeset = vega.changeset().insert([{'a':50,'b':10}]);
          myViz.then(viz => viz.view.change('exampletable',changeset).run());}
      </script>
  </BODY>
</HTML>
