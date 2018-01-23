#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct Coords {
    int w;
    int k;
} coords;

int can1MakeAMove (int tab[][20], coords c);
int can2MakeAMove (int tab[][20], coords c);
void MakeA1Move (int tab[][20], coords c);
void MakeA2Move (int tab[][20], coords c);
coords readWhere (const char *name);
void updateBoard();


coords readInfoAboutAMove(char message[]);
int can2MakeAMoveAtAll(int tab[][20], int wys, int szer);
int can1MakeAMoveAtAll(int tab[][20], int wys, int szer);

coords endOfTheGame(int tab[][20]);

void prepareMessage(char s[], coords res);
void appendMessage(char s[], GtkWidget *windowEnd);
