#include <stdio.h>
#include "fifo.h"
#include "reversi.h"

///jak zrobic to czekanie zeby nie bylo az tak debilne


GtkWidget *window, *window1, *windowWait;
int gracz;
static PipesPtr potoki;

int szer=-1, wys=-1;
gboolean pomoc;
gboolean otherIsReady = 0;
gboolean boardPrepared = 0;
gboolean change1ToRed;

GtkWidget* tablica[20][20];
int gra[20][20] = {0};

gchar message[10];


void pokazBlad(char *komunikat)
{
    GtkWidget *dialog;
    dialog=gtk_message_dialog_new (GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,
				   GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,"%s",komunikat);
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}


void makeBoard () {
    GtkWidget *child1 = gtk_bin_get_child(GTK_BIN(window));
    GList *lista = gtk_container_get_children(GTK_CONTAINER(child1));
    GtkWidget *plansza = lista->data;
    for (int i=0; i<wys; i++) {
        for (int j=0; j<szer; j++) {
            GtkWidget *pole = gtk_frame_new(NULL);
            GdkPixbuf *pixbuf;
            if (((i+1)*2==wys && (j+1)*2==szer) || (i*2==wys && j*2==szer)) {
                pixbuf = gdk_pixbuf_new_from_file("black.png", NULL);
                if (change1ToRed) {
                    gra[j][i] = 2;
                } else {
                    gra[j][i] = 1;
                }
            } else if ((i*2==wys && (j+1)*2==szer) || ((i+1)*2==wys && j*2==szer)) {
                pixbuf = gdk_pixbuf_new_from_file("red.png", NULL);
                if (change1ToRed) {
                    gra[j][i] = 1;
                } else {
                    gra[j][i] = 2;
                }
            } else {
                pixbuf = gdk_pixbuf_new_from_file("blank.png", NULL);
                gra[j][i] = 0;
            }


           /* GdkScreen *screen = gdk_screen_get_default ();
            gint h = gdk_screen_get_height(screen);
            gint w = gdk_screen_get_width(screen);
            */


            GdkPixbuf *newpixbuf = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), 100, 100, GDK_INTERP_NEAREST);
            GtkWidget *image = gtk_image_new_from_pixbuf(GDK_PIXBUF(newpixbuf));
            gtk_container_add(GTK_CONTAINER(pole), image);
            tablica[j][i]=pole;
            gtk_grid_attach(GTK_GRID(plansza), tablica[j][i], j, i, 1, 1);
        }
    }
    gtk_widget_show_all(window);
    gtk_widget_destroy(windowWait);

    /*
    for (int i=0; i<wys; i++) {
        for (int j=0; j<szer; j++) {
            printf("%d ", can1MakeAMove(gra, i, j));
        }
        printf("\n");
    }
    */

}

void readInfoAndDestroyWindow ()
{
    GtkWidget *child = gtk_bin_get_child(GTK_BIN(window1));
    GList *list = gtk_container_get_children(GTK_CONTAINER(child));
    list = g_list_nth(list, 2);
    GtkWidget *pudelko = list->data;
    list = gtk_container_get_children(GTK_CONTAINER(pudelko));
    list = g_list_nth(list, 0);
    GtkWidget *chybagrid = list->data;
    GtkWidget *pole1 = gtk_grid_get_child_at(GTK_GRID(chybagrid), 2, 1);
    const gchar *wejscie;
    wejscie = gtk_entry_get_text (GTK_ENTRY(pole1));
    wys = atoi(wejscie);
    g_print ("Wprowadzono: %d\n", wys);
    GtkWidget *pole2 = gtk_grid_get_child_at(GTK_GRID(chybagrid), 2, 2);
    const gchar *wejscie1;
    wejscie1 = gtk_entry_get_text (GTK_ENTRY(pole2));
    szer = atoi(wejscie1);
    g_print ("Wprowadzono: %d\n", szer);
    GtkWidget *check = gtk_grid_get_child_at(GTK_GRID(chybagrid), 1, 3);
    pomoc = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check));
    g_print("Czy pomoc: %d\n", pomoc);
    GtkWidget *check1 = gtk_grid_get_child_at(GTK_GRID(chybagrid), 1, 4);
    change1ToRed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1));
    g_print("Czy zmiana na czerwone: %d\n", change1ToRed);
    if (wys%2==0 && szer%2==0 && wys>=6 && szer>=6 && wys<=18 && szer<=18) {
        ///jesli gracz 2 juz zrobil rzeczy
        pobierz_tekst1();
        if (message[0]=='2') {
            otherIsReady=1;
            makeBoard();
        }
        sprintf(message, "1rh%dw%dk", wys, szer);
        przekaz_tekst();
        if (!otherIsReady){
            gtk_widget_show_all(windowWait);
            printf("Waiting\n");
        }
        g_timeout_add(100,pobierz_tekst,NULL);
        gtk_widget_destroy(GTK_WIDGET(window1));
    } else {
        szer=-1;
        wys=-1;
        child = gtk_bin_get_child(GTK_BIN(window1));
        list = gtk_container_get_children(GTK_CONTAINER(child));
        list = g_list_nth(list, 2);
        GtkWidget *pudelko = list->data;
        list = gtk_container_get_children(GTK_CONTAINER(pudelko));
        list = g_list_nth(list, 1);
        GtkWidget *pudlo = list->data;
        list = gtk_container_get_children(GTK_CONTAINER(pudlo));
        list = g_list_nth(list, 1);
        gtk_label_set_text(GTK_LABEL(list->data),"Read carefully:\nValues inserted above should be even numbers from range <6,18>");
    }
}

void readInfoProperly() {
    char th[2];
    th[0]=message[3];
    if (message[4]!='s') {
        th[1]=message[4];
    }
    wys = atoi(th);
    if (message[5]!='s') {
        th[0]=message[5];
        if (message[6]!='k') {
            th[1]=message[6];
        } else {
            th[1]='\0';
        }
    } else {
        th[0]=message[6];
        if (message[7]!='k') {
            th[1]=message[7];
        } else {
            th[1]='\0';
        }
    }
    szer=atoi(th);
}

void readAndDestroyWindow ()
{
    GtkWidget *child = gtk_bin_get_child(GTK_BIN(window1));
    GList *list = gtk_container_get_children(GTK_CONTAINER(child));
    list = g_list_nth(list, 2);
    GtkWidget *przycisk = list->data;
    pomoc = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(przycisk));
    g_print("Czy pomoc: %d\n", pomoc);
    ///wait for things
    pobierz_tekst1();

    if (message[0]=='1') {
        otherIsReady=1;
        readInfoProperly();
        makeBoard();
    }
    sprintf(message, "2r");
    przekaz_tekst();
    g_timeout_add(100,pobierz_tekst,NULL);

    if (!otherIsReady){
        gtk_widget_show_all(windowWait);
        gtk_window_set_keep_above(GTK_WINDOW(windowWait), TRUE);
    }
    gtk_widget_destroy(window1);
}




int main(int argc,char *argv[])
{
    if ((potoki=initPipes(argc,argv)) == NULL)
        return 1;
    gtk_init(&argc, &argv);


    if (argc == 2 && strcmp(argv[1],"A") == 0) {
        gracz = 1;
    } else {
        gracz = 2;
    }


    ///wybieranie opcji rozgrywki (gracz 1)

    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window1),"Reversi - options");
    gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
   // g_signal_connect(G_OBJECT(window1), "destroy",G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *boxMain = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window1), boxMain);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(boxMain), box1);

    GtkWidget *ramka = gtk_frame_new(NULL);
    GtkWidget *napis = gtk_label_new("\nREVERSI\n");
    gtk_container_add(GTK_CONTAINER(ramka), napis);
    gtk_box_pack_start(GTK_BOX(box1), ramka, TRUE, TRUE, 20);

    windowWait = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(windowWait),"Hold on...");
    gtk_window_set_position(GTK_WINDOW(windowWait),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(windowWait), 10);
    GtkWidget *boxWait = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(windowWait), boxWait);
    GtkWidget *napisWait = gtk_label_new(NULL);
    gtk_container_add(GTK_CONTAINER(boxWait), napisWait);


    if (gracz == 1) {
        GtkWidget *yoText = gtk_label_new("You're player 1, so you choose board properties");
        gtk_container_add(GTK_CONTAINER(boxMain), yoText);

        GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_container_add(GTK_CONTAINER(boxMain), box2);

        GtkWidget *grid = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
        gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
        gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
        gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
        gtk_box_pack_start(GTK_BOX(box2), grid, TRUE, TRUE, 10);

        GtkWidget *opcja_wys_planszy = gtk_label_new("Choose board heigth:");
        GtkWidget *opcja_szer_planszy = gtk_label_new("Choose board width:");

        GtkWidget *text1 = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(text1), 100);
        gtk_entry_set_alignment(GTK_ENTRY(text1), 1);
        gtk_entry_set_text(GTK_ENTRY(text1), "8");

        GtkWidget *text2 = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(text2), 100);
        gtk_entry_set_alignment(GTK_ENTRY(text2), 1);
        gtk_entry_set_text(GTK_ENTRY(text2), "8");

        gtk_grid_attach(GTK_GRID(grid), opcja_wys_planszy, 1, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), opcja_szer_planszy, 1, 2, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), text1, 2, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), text2, 2, 2, 1, 1);


        ///ogarnac tego buttona
        GtkWidget *checkbox = gtk_check_button_new_with_label("Show hints");
        gtk_grid_attach(GTK_GRID(grid), checkbox, 1, 3, 2, 1);

        GtkWidget *checkbox1 = gtk_check_button_new_with_label("Change my discs to red (default black)");
        gtk_grid_attach(GTK_GRID(grid), checkbox1, 1, 4, 2, 1);

        ///i tego, czemu to zajmuje caaala przestrzen halo
        GtkWidget *button = gtk_button_new_with_label("Start game");
        GtkWidget *box3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_box_set_homogeneous(GTK_BOX(box3), TRUE);
        gtk_container_add(GTK_CONTAINER(box2), box3);
        gtk_box_pack_start(GTK_BOX(box3), button, TRUE, FALSE, 10);

        g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(readInfoAndDestroyWindow), NULL);


        GtkWidget *valueInfo = gtk_label_new("Values inserted above should be even numbers from range <6,18>");
        gtk_container_add(GTK_CONTAINER(box3), valueInfo);

        gtk_label_set_text(GTK_LABEL(napisWait),"\nWaiting for player 2 to choose their options\n");

    } else {

        ///wybieranie opcji rozgrywki - gracz 2

        GtkWidget *yoText = gtk_label_new("You're player 2, so you wait for player 1 to choose board properties");
        gtk_container_add(GTK_CONTAINER(boxMain), yoText);

        GtkWidget *checkbox = gtk_check_button_new_with_label("Show hints");
        gtk_box_pack_start(GTK_BOX(boxMain), checkbox, TRUE, FALSE, 0);

        GtkWidget *button = gtk_button_new_with_label("Start game");
        gtk_container_add(GTK_CONTAINER(boxMain), button);

        g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(readAndDestroyWindow), NULL);

        gtk_label_set_text(GTK_LABEL(napisWait),"\nWaiting for player 1 to choose their options\n");
    }

    gtk_widget_show_all(window1);

    ///generowanie planszy

    char name[100];
    sprintf(name, "Reversi - game - player %d", gracz);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),name);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *mainBoxGame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), mainBoxGame);

    GtkWidget *plansza = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(plansza), 0);
    gtk_grid_set_row_homogeneous(GTK_GRID(plansza), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(plansza), 0);
    gtk_grid_set_column_homogeneous(GTK_GRID(plansza), TRUE);
    gtk_box_pack_start(GTK_BOX(mainBoxGame), plansza, TRUE, TRUE, 10);

    ///moze go dodac do tego grida?
    GtkWidget *zakonczgre = gtk_button_new_with_label("Surrender");
    gtk_box_pack_end(GTK_BOX(mainBoxGame), zakonczgre, FALSE, TRUE, 10);
    g_signal_connect(G_OBJECT(zakonczgre), "clicked", G_CALLBACK(zakoncz), window);

    //GdkScreen *screen = gdk_screen_get_default ();
   // GdkScreen *screen = gtk_window_get_screen(GTK_WINDOW(window1));
   // printf("%d %d\n", gdk_screen_get_height(screen), gdk_screen_get_width(screen));
    /*
    GdkDisplay *display = gdk_display_get_default();
    printf("%d\n", gdk_display_get_n_monitors(display));
    GdkMonitor *monitor = gdk_display_get_monitor(display, 0);
    printf("%s\n", gdk_monitor_get_model(monitor));
    GdkRectangle *geometry;
    gdk_monitor_get_geometry(monitor, geometry);
    printf("%d %d\n", geometry->height, geometry->width);
    */
    gtk_main();
    return 0;
}


void przekaz_tekst()
{
    sendStringToPipe(potoki, message);
}

gboolean pobierz_tekst(gpointer data)
{
    printf("%s\n", message);
    getStringFromPipe(potoki,message,20);
    if (message[0]=='1' && message[1]=='r' && gracz==2 && !boardPrepared) {
        boardPrepared = 1;
        readInfoProperly();
        makeBoard();
    }
    if (message[0]=='2' && message[1]=='r' && gracz==1 && !boardPrepared) {
        boardPrepared = 1;
        makeBoard();
    }
    return TRUE;
}

void pobierz_tekst1() {
    getStringFromPipe(potoki,message,20);
}

void zakoncz(GtkWidget *widget, gpointer data)
{
  closePipes(potoki);
  gtk_main_quit();
}

