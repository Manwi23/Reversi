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


void sendText();
gboolean getText(gpointer data);
void getText1();
void surrender(GtkWidget *widget, gpointer data);
