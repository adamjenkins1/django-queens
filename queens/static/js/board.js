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
  positionString = "";
  for(i = 0; i < 8; i++) {
    random = getRandomInt(1,7);
    if(random == 7) {
      chance = getRandomInt(0,1);
      if(chance == 0) {
        positionString += 'q7';
      }
      else if(chance == 1) {
        positionString += '7q';
      }
    }
    else {
      positionString += parseInt(7 - random) + 'q' + parseInt(random);
    }

    if(i < 7) {
      positionString += '/';
    }
  }

  //positionString = 'qqqqqqqq/qqqqqqqq/qqqqqqqq/qqqqqqqq/qqqqqqqq/qqqqqqqq/qqqqqqqq/qqqqqqqq';
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

