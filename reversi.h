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
int can2MakeAMoveAtAll(int tab[][20], int heigth, int width);
int can1MakeAMoveAtAll(int tab[][20], int heigth, int width);

coords endOfTheGame(int tab[][20]);

void prepareMessage(char s[], coords res, gchar myName[], gchar hisName[]);
void appendMessage(char s[], GtkWidget *windowEnd, int type);

void appendDisc(int type, GtkWidget *board, int i, int j, int imgSize);

coords readInfoProperly();

void appendHints(GtkWidget *board, int heigth, int width, int game[][20], int imgSize);
void destroyNewGameButton(GtkWidget *window);
int setImgSize(int heigth, int width);
void updateNames();
void getName(gchar nname[]);
void checkNames(int player, gchar myName[], gchar hisName[]);

void endMyGame();
void newGameAfterTheEnd();
void newGameAfterTheEndButton();
void canWePleasePlayANewGameNow();
void returnToGame();
void showAskWindow();
void denyAndReturnToGame();
void agreeAndPlayNew();
void newGame();
void closeAndReturn();
void propositionDenied();
void clearBoard(int heigth, int width, gboolean change, int game[][20]);
void appendWaitingInfo(GtkWidget *window);
void renewWaitingInfo(GtkWidget *window);
void appendWantingInfo(GtkWidget *window);
