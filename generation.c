#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generation.h"

// creates row boundary
void row_line(void) {
  printf("\n");
  for (int i = 0; i < ncols; i++) {
    printf("----");
  }
  printf("-\n");
}

int count_live_neighbours(int a[nrows][ncols], int r, int c) {
  int i, j, count = 0;
  for (i = r - 1; i <= r + 1; i++) {
    for (j = c - 1; j <= c + 1; j++) {
      if ((i == r && j == c) || (i < 0 || j < 0) ||
          (i >= nrows || j >= ncols)) {
        continue;
      }
      if (a[i][j] == 1) {
        count++;
      }
    }
  }
  return count;
}

int count_creatures(int currentGenMatrix[nrows][ncols]) {
  int i, j;
  int ncreatures = 0;

  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++) {
      if (currentGenMatrix[i][j] == 1) {
        ncreatures++;
      }
    }
  }
  return ncreatures;
}

int anyCreature(int currentGenMatrix[nrows][ncols]) {
  int ncreatures = count_creatures(currentGenMatrix);
  if (ncreatures == 0)
    return 0;
  else
    return 1;
}

int gen_init_state(int firstGen[nrows][ncols]) {
  int i, j;
  time_t t;
  srandom((unsigned) time(&t));

  for (i = 0; i < nrows; i++)
    for (j = 0; j < ncols; j++)
      firstGen[i][j] = rand() % 2;

  return firstGen[nrows][ncols];
}

void print_first_gen(int firstGen[nrows][ncols]) {
  int i, j;

  printf("Initial Stage:");
  row_line();
  for (i = 0; i < nrows; i++) {
    printf("|");
    for (j = 0; j < ncols; j++) {
      printf(" %d |", firstGen[i][j]);
    }
    row_line();
  }
}

int sameAsLastGen(int lastGen[nrows][ncols], int currentGen[nrows][ncols]) {
  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols; j++) {
      if (lastGen[i][j] != currentGen[i][j]) {
        return 0; // Arrays are not equal
      }
    }
  }
  return 1; // Arrays are equal
}

int gen_next_state(int currentGenMatrix[nrows][ncols]) {
  int i, j;
  int neighbour_live_cell;
  int nextGenMatrix[nrows][ncols];

  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++) {
      neighbour_live_cell = count_live_neighbours(currentGenMatrix, i, j);
      if (currentGenMatrix[i][j] == 1 &&
          (neighbour_live_cell == 2 || neighbour_live_cell == 3)) {
        nextGenMatrix[i][j] = 1;
      }

      else if (currentGenMatrix[i][j] == 0 && neighbour_live_cell == 3) {
        nextGenMatrix[i][j] = 1;
      }

      else {
        nextGenMatrix[i][j] = 0;
      }
    }
  }

  if (sameAsLastGen(currentGenMatrix, nextGenMatrix) == 1) {
    printf("Generations are not changing anymore. End of game!\n");
    exit(0);
  }

  for (i = 0; i < nrows; i++)
    for (j = 0; j < ncols; j++)
      currentGenMatrix[i][j] = nextGenMatrix[i][j];

  return currentGenMatrix[nrows][ncols];
}

void print_gen(int generation, int currentGenMatrix[nrows][ncols]) {
  int i, j;

  printf("\nGeneration %i:", generation);
  row_line();
  for (i = 0; i < nrows; i++) {
    printf("|");
    for (j = 0; j < ncols; j++) {
      printf(" %d |", currentGenMatrix[i][j]);
    }
    row_line();
  }
}
