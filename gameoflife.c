#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// #include "flags.h"
#include "generation.h"

// change row and column value to set the canvas size
int nrows = 5;
int ncols = 5;
int MaxGen = 100;

int main(int argc, char *argv[]) {
  int currentGen = 0;
  bool seedFileDefined = false;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
        printf("Usage: gameoflife [options]\n");
        printf("Options:\n");
        printf("  -s, --board-size <rows> <columns>\n");
        printf("  -r, --rows <rows>\n");
        printf("  -c, --columns <columns>\n");
        printf("  -m, --max-gen <maxgen>\n");
        printf("  --help\n");
        exit(0);
      } else if (strcmp(argv[i], "--board-size") == 0 ||
                 strcmp(argv[i], "-s") == 0) {
        nrows = atoi(argv[i + 1]);
        ncols = atoi(argv[i + 2]);
        i += 2;
      } else if (strcmp(argv[i], "--rows") == 0 || strcmp(argv[i], "-r") == 0) {
        nrows = atoi(argv[i + 1]);
        i += 1;
      } else if (strcmp(argv[i], "--columns") == 0 ||
                 strcmp(argv[i], "-c") == 0) {
        ncols = atoi(argv[i + 1]);
        i += 1;
      } else if (strcmp(argv[i], "--max-gen") == 0 ||
                 strcmp(argv[i], "-m") == 0) {
        MaxGen = atoi(argv[i + 1]);
        i += 1;
      }
    }
  }

  int currentGenMtx[nrows][ncols];

  if (!seedFileDefined) {
    gen_init_state(currentGenMtx);
  }

  print_first_gen(currentGenMtx);

  while (currentGen <= MaxGen) {
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
