#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "flags.h"
#include "generation.h"

//change row and column value to set the canvas size
int nrows = 5;
int ncols = 5;
int MaxGen = 100;

static volatile int keepRunning = 1;
void intHandler(int keepRunning) {
  keepRunning = 0;
}


int main(int argc, char *argv[]){
  int currentGenMtx[nrows][ncols];

  int currentGen = 0;

  gen_init_state(currentGenMtx);
  print_first_gen(currentGenMtx);


  signal(SIGINT, intHandler);
  while (keepRunning) {
    currentGen += 1;

    gen_next_state(currentGenMtx);
    print_gen(currentGen, currentGenMtx);

    if (anyCreature(currentGenMtx) == 0) {
      printf("\nNo creatures left. End of game!");
      exit(0);
    }

    if (currentGen == MaxGen) {
      printf("\nMax number of %i generetions reached! End of game!", MaxGen);
      exit(0);
    }
  }

	return 0;
}
