#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct Coords {
    int w;
    int k;
} coords;

int can1MakeAMove (int tab[][20], int a, int b);
int can2MakeAMove (int tab[][20], int a, int b);
void MakeA1Move (int tab[][20], int a, int b);
void MakeA2Move (int tab[][20], int a, int b);
coords readWhere (const char *name);
void updateBoard();
