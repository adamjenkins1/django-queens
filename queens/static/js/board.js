function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

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

var delay = 1000;
var looping = true;


function randomQueens() {
  var positionString = "";
  var choices = [0, 1, 2, 3, 4, 5, 6, 7];

  while(true) {
    random = getRandomInt(0,7);
    var index = choices.indexOf(random);
    if(index > -1) {
      choices.splice(index, 1);
      if(random == 0) {
        positionString += 'q' + 7;
      }
      else if(random == 7) {
        positionString += 7 + 'q';
      }
      else {
        positionString += random + 'q' + (7 - random);
      }

      if(choices.length > 0) {
        positionString += '/';
      }
    }
    if(choices.length == 0) {
      break;
    }
  }

  console.log(positionString);
  board1.position(positionString);
}

var intervalId = setInterval(randomQueens, delay);

$('#toggleQueens').on('click', function () {
  $(this).toggleClass("active");
  if(looping == true) {
    clearInterval(intervalId);
    looping = false;
  }
  else {
    intervalId = setInterval(randomQueens, delay);
    looping = true;
  }
});

