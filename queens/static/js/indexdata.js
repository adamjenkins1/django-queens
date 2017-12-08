var app = new Vue({
  el: '#app',
  data: {
    question_list: [],

  },
  mounted() {
    this.loadData();

    setInterval(function () {
      this.loadData();
    }.bind(this), 5000);
  },
  methods: {
    loadData: function () {
      $.get('/polls/indexdata', function (response) {
        this.question_list = response;
        console.log(response);
      }.bind(this));
    }
  }
});
