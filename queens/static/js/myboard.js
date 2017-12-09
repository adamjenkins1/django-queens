var position = {
  a1: 'bQ',
  b2: 'bQ',
  c3: 'bQ',
  d4: 'bQ',
  e5: 'bQ',
  f6: 'bQ',
  g7: 'bQ',
  h8: 'bQ',
};

var board1 = ChessBoard('board1', position);

$('#solve').on('click', function () {
  var queens = parseInt($('#numQueens').val());
  var method = $('#method').val();
  if(queens >= 4 && queens <= 8 && (method == 'Recursive')) {

    var url = '/solve/' + queens + '/' + method + '/';
    $.post(url)
      .done(function(result) {
        console.log(result);
      })
    .fail(function(xhr, status, error) {
      if(xhr.status == 400) {
        console.log('something');
      }
    });
  }
  else if(isNaN(queens)) {
    alert('Choose a number of queens between 4 and 8 inclusive.');
    $('#numQueens').val('');
  }
  else if(method != 'Recursive') {
    alert('Invalid algorithm: ' + method);
  }
  else {
    alert('Invalid number of Queens: ' + queens + '. Pick a value between 4 and 8 inclusive.');
    $('#numQueens').val('');
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
