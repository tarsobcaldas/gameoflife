#ifndef GENERATION_H
#define GENERATION_H

extern int nrows;
extern int ncols;
extern int currentGenMtx;


void row_line(void);
int count_live_neighbours(int a[nrows][ncols], int r, int c);
int count_creatures(int currentGenMatrix[nrows][ncols]);
int anyCreature(int currentGenMatrix[nrows][ncols]);
int gen_init_state(int a[nrows][ncols]);
void print_first_gen(int first[nrows][ncols]);
int gen_next_state(int currentGenMatrix[nrows][ncols]);
void print_gen(int generation, int currentGenMatrix[nrows][ncols]);

#endif
