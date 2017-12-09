var board1 = ChessBoard('board1');
var solveClicked = false;

$('#solve').on('click', function () {
  if(solveClicked == false) {
    solveClicked = true;
    var queens = parseInt($('#numQueens').val());
    var method = $('#method').val();
    if(queens >= 4 && queens <= 8 && (method == 'Recursive')) {

      var url = '/solve/' + queens + '/' + method + '/';
      $.post(url)
        .done(function(result) {
          console.log(result);
          board1.position(result);
          solveClicked = false;
        })
      .fail(function(xhr, status, error) {
        if(xhr.status == 400) {
          alert('Unable to find soltion');
          solveClicked = false;
        }
      });
    }
    else if(isNaN(queens)) {
      alert('Choose a number of queens between 4 and 8 inclusive.');
      $('#numQueens').val('');
      solveClicked = false;
    }
    else if(method != 'Recursive') {
      alert('Invalid algorithm: ' + method);
      solveClicked = false;
    }
    else {
      alert('Invalid number of Queens: ' + queens + '. Pick a value between 4 and 8 inclusive.');
      $('#numQueens').val('');
      solveClicked = false;
    }
  }
});

function csrfSafeMethod(method) {
  return (/^(GET|HEAD|OPTIONS|TRACE)$/.test(method));
}

$.ajaxSetup({
  beforeSend: function(xhr, settings) {
    if (!csrfSafeMethod(settings.type) && !this.crossDomain) {
      xhr.setRequestHeader('X-CSRFToken', csrftoken);
    }
  }
});
