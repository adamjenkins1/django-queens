var count = 0;
var app = new Vue({
  el: '#app',
  data: {
    chessDataList: [],
    numRows: Number,
  },
  mounted() {
    this.loadData();

    setInterval(function () {
      this.loadData();
    }.bind(this), 5000);
  },
  methods: {
    loadData: function () {
      $.get('/jsondata', function (response) {
        this.chessDataList = response;
        this.numRows = this.chessDataList.length;
        var dataPointsRecursive = this.chessDataList.filter(function(e) {
          return e.algorithm == 'Recursive';
        }).map(function(e) {
          return {
            x: e.queens,
            y: e.time
          };
        });

        Chart.defaults.global.animation.duration = 0;
        var color = Chart.helpers.color;
        var ctx = document.getElementById("canvas").getContext("2d");
        var scatterChart = new Chart(ctx, {
          type: 'scatter',
          data: {
            datasets: [{
              label: 'Recursive',
              borderColor: 'rgb(255, 65, 54)',
              backgroundColor: color('rgb(255, 65, 54)').alpha(0.2).rgbString(),
              data: dataPointsRecursive
            }
            ]
          },
          options: {
            scales: {
              xAxes: [{
                ticks: {
                  min: 4,
                  max: 8,
                  stepSize: 1
                },
                type: 'linear',
                position: 'bottom',
                scaleLabel: {
                  display: true,
                  labelString: '# of Queens',
                  fontSize: 15
                }
              }],
              yAxes: [{
                ticks: {
                  stepSize: 0.2 
                },
                scaleLabel: {
                  display: true,
                  labelString: 'Time (ms)',
                  fontSize: 15
                }
              }]
            },
            title: {
              display: true,
              fontSize: 25,
              text: 'Number of Queens vs Time (ms)'
            },
          }
        });

        var recursiveTime = dataPointsRecursive.map(e => e.y);
        var recursiveX = dataPointsRecursive.map(e => e.x);

        var recursiveBox = {
          x: recursiveX,
          y: recursiveTime,
          name: 'Recursive',
          marker: {
            color: 'rgb(255, 65, 54)'
          },
          boxmean: true,
          type: 'box',
          orientation: 'v'
        };

        var layout = {
          title: 'Number of Queens vs Time (ms) by Algorithm',
          yaxis: {
            title: 'Time (ms)',
          },
          xaxis: {
            title: '# of Queens',
          },
          boxmode: 'group'
        };

        var data = [recursiveBox];
        Plotly.newPlot('box', data, layout);

      }.bind(this));
    }
  }
});

