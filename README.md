# Conway's Game of Life

This repository contains an implementation of the [game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) algorithm in C, that generates 
a random first matrix and iterates through generations until either
    * the max number of generations is reached (default is 100);
    * the new generation is the same as last;
    * all creatures die.

To build, you can use the follwing commands:

```bash
git clone https://github.com/tarsobcaldas/gameoflife.git && cd gameoflife;
mkdir build && cd build;
cmake ..
make
```

To run the program, just use
```
./gameoflife [options]
```

The options of the program are the following:
```
  -s, --board-size <rows> <columns>
  -r, --rows <rows>                 (default is 5)
  -c, --columns <columns>           (default is 5)
  -m, --max-gen <maxgen>            (default is 100)
  --help
```
