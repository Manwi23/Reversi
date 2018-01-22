#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#define MAKS_DL_TEKSTU 10000


typedef struct pipes *PipesPtr;

PipesPtr initPipes(int argc, char *argv[]);
void     sendStringToPipe(PipesPtr channel, const char *data);
bool     getStringFromPipe(PipesPtr channel, char *buffer, size_t size);
void     closePipes(PipesPtr channel);


///kopiowane z maina

///zakoncz i pobierz_tekst byly static

void przekaz_tekst();
gboolean pobierz_tekst(gpointer data);
void pobierz_tekst1();
void zakoncz(GtkWidget *widget, gpointer data);
