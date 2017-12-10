# Django Queens

## About
* This [Django][django link] web app is designed to solve the [Queens problem][queens link]
  with the number of Queens being between 4 and 8 inclusive and uses 
  [chessboard.js][chessboardjs link], [Vue.js][vuejs link], [jQuery][jquery link], 
  and [Bootstrap][bootstrap link] for front end, and [C++][c++ link] 
  in the back end to implement algorithms. Click [here][divc link] to see a live demo.

## Requirements
* All that is required to run this web app is [Python 3][python link], 
  [Django][django link] >= 1.11.5, g++, and make.

## Running the project
* To run this project, first fork and clone the git repository. To run this project locally, make sure to set 
  `DEBUG = True` in `project/settings.py`, otherwise the Django web server will not serve the 
  required static files. Once that has been changed, type make run PORT=&lt;port&gt;. This will compile 
  the C++ program required for running the algorithms and start the Django web server. If no port is specified, 
  Django will start the web server on port 8000. 
* To install requirements run `make pyreqs`.
    This is also done automatically when `make run` is called

## The Algorithms
* [Recursive][recursion link]

## Authors
* [Adam Jenkins][adam github]

[adam github]:	https://github.com/adamjenkins1

[jquery link]: https://jquery.com/
[bootstrap link]: https://getbootstrap.com/
[python link]: https://www.python.org/downloads/
[django link]: https://www.djangoproject.com/
[queens link]: https://en.wikipedia.org/wiki/Eight_queens_puzzle
[chessboardjs link]: https://chessboardjs.com/
[vuejs link]: https://vuejs.org/
[c++ link]: https://en.wikipedia.org/wiki/C%2B%2B
[recursion link]: https://en.wikipedia.org/wiki/Recursion_(computer_science)
[divc link]: http://queens.divisionc.com
