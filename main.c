#include <stdio.h>
#include "fifo.h"
#include "reversi.h"


GtkWidget *window, *window1, *windowWait, *windowEnd;
int player;
static PipesPtr streams;

int width=-1, heigth=-1;
gboolean hilfe;
gboolean otherIsReady = 0;
gboolean boardPrepared = 0;
gboolean change1ToRed = 0;
int whosTurn = 1;

int game[20][20] = {0};

gchar message[10];


static gboolean button_press_callback (GtkWidget *event_box, GdkEventButton *event, gpointer data) {
    const char *name = gtk_widget_get_name(event_box);
    coords c = readWhere(name);
    if (whosTurn == 1 && can1MakeAMove(game, c)==1 && player==1) {
        MakeA1Move(game, c);
        whosTurn = 2;

        sprintf(message, "1mh%dw%dk", c.w, c.k);
        sendText();

        if (can2MakeAMoveAtAll(game, heigth, width)==0) {
            if (can1MakeAMoveAtAll(game, heigth, width)==0) {
                coords res =  endOfTheGame(game);
                char s[100];
                prepareMessage(s, res);
                appendMessage(s, windowEnd);
                gtk_widget_show_all(windowEnd);
            } else {
                whosTurn = 1;
            }
        }

        updateBoard();

    } else if (whosTurn == 2 && can2MakeAMove(game, c)==1 && player==2) {
        MakeA2Move(game, c);
        whosTurn = 1;

        sprintf(message, "2mh%dw%dk", c.w, c.k);
        sendText();

        if (can1MakeAMoveAtAll(game, heigth, width)==0) {
            if (can2MakeAMoveAtAll(game, heigth, width)==0) {
                coords res =  endOfTheGame(game);
                char s[100];
                prepareMessage(s, res);
                appendMessage(s, windowEnd);
                gtk_widget_show_all(windowEnd);
            } else {
                whosTurn = 2;
            }
        }

        updateBoard();
    }
    return TRUE;
}

void updateBoard() {
    GtkWidget *child = gtk_bin_get_child(GTK_BIN(window));
    GList *list = gtk_container_get_children(GTK_CONTAINER(child));
    GtkWidget *board = list->data;
    coords c;
    for (int i=0; i<heigth; i++) {
        for (int j=0; j<width; j++) {
            c.w = i;
            c.k = j;
            if (game[i][j]==1) {
                if (!change1ToRed) {
                    appendDisc(1, board, i, j);
                } else {
                    appendDisc(2, board, i, j);
                }
            } else if (game[i][j]==2) {
                if (!change1ToRed) {
                    appendDisc(2, board, i, j);
                } else {
                    appendDisc(1, board, i, j);
                }
            } else if (game[i][j]==0 && whosTurn==1 && player==1 && can1MakeAMove(game, c)==1 && hilfe==1) {
                appendDisc(3, board, i, j);
            } else if (game[i][j]==0 && whosTurn==2 && player==2 && can2MakeAMove(game, c)==1 && hilfe==1) {
                appendDisc(3, board, i, j);
            } else {
                appendDisc(4, board, i, j);
            }
        }
    }

    gtk_widget_show_all(board);

    return;
}



void makeBoard () {
    GtkWidget *child1 = gtk_bin_get_child(GTK_BIN(window));
    GList *lista = gtk_container_get_children(GTK_CONTAINER(child1));
    GtkWidget *board = lista->data;

    char name[5];

    for (int i=0; i<heigth; i++) {
        for (int j=0; j<width; j++) {
            GtkWidget *field = gtk_frame_new(NULL);
            GdkPixbuf *pixbuf;
            if (((i+1)*2==heigth && (j+1)*2==width) || (i*2==heigth && j*2==width)) {
                pixbuf = gdk_pixbuf_new_from_file("black.png", NULL);
                if (change1ToRed) {
                    game[i][j] = 2;
                } else {
                    game[i][j] = 1;
                }
            } else if ((i*2==heigth && (j+1)*2==width) || ((i+1)*2==heigth && j*2==width)) {
                pixbuf = gdk_pixbuf_new_from_file("red.png", NULL);
                if (change1ToRed) {
                    game[i][j] = 1;
                } else {
                    game[i][j] = 2;
                }
            } else {
                pixbuf = gdk_pixbuf_new_from_file("blank.png", NULL);
                game[i][j] = 0;
            }

            GdkPixbuf *newpixbuf = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), 100, 100, GDK_INTERP_NEAREST);
            GtkWidget *image = gtk_image_new_from_pixbuf(GDK_PIXBUF(newpixbuf));

            GtkWidget *eventBox = gtk_event_box_new();
            gtk_container_add(GTK_CONTAINER(field), eventBox);
            gtk_container_add(GTK_CONTAINER(eventBox), image);
            g_signal_connect (G_OBJECT (eventBox), "button_press_event", G_CALLBACK (button_press_callback), image);

            sprintf(name, "%d,%d", i, j);
            gtk_widget_set_name(eventBox, name);
            gtk_grid_attach(GTK_GRID(board), field, i, j, 1, 1);
        }
    }

    if (hilfe==1 && player==1) {
        appendHints(board, heigth, width, game);
    }

    gtk_widget_show_all(window);
    gtk_widget_destroy(windowWait);

}

void readInfoAndDestroyWindow ()
{
    GtkWidget *child = gtk_bin_get_child(GTK_BIN(window1));
    GList *list = gtk_container_get_children(GTK_CONTAINER(child));
    list = g_list_nth(list, 2);
    GtkWidget *smallbox = list->data;
    list = gtk_container_get_children(GTK_CONTAINER(smallbox));
    list = g_list_nth(list, 0);
    GtkWidget *grid = list->data;
    GtkWidget *field1 = gtk_grid_get_child_at(GTK_GRID(grid), 2, 1);
    const gchar *entry = gtk_entry_get_text (GTK_ENTRY(field1));
    heigth = atoi(entry);
    GtkWidget *field2 = gtk_grid_get_child_at(GTK_GRID(grid), 2, 2);
    const gchar *entry1 = gtk_entry_get_text (GTK_ENTRY(field2));
    width = atoi(entry1);
    GtkWidget *check = gtk_grid_get_child_at(GTK_GRID(grid), 1, 3);
    hilfe = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check));
    GtkWidget *check1 = gtk_grid_get_child_at(GTK_GRID(grid), 1, 4);
    change1ToRed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1));
    if (heigth%2==0 && width%2==0 && heigth>=6 && width>=6 && heigth<=18 && width<=18) {
        getText1();
        if (message[0]=='2') {
            otherIsReady=1;
            makeBoard();
        }
        sprintf(message, "1rh%dw%dk%d", heigth, width, change1ToRed);
        sendText();
        if (!otherIsReady){
            gtk_widget_show_all(windowWait);
        }
        g_timeout_add(100,getText,NULL);
        gtk_widget_destroy(GTK_WIDGET(window1));
    } else {
        width=-1;
        heigth=-1;
        child = gtk_bin_get_child(GTK_BIN(window1));
        list = gtk_container_get_children(GTK_CONTAINER(child));
        list = g_list_nth(list, 2);
        GtkWidget *smallbox = list->data;
        list = gtk_container_get_children(GTK_CONTAINER(smallbox));
        list = g_list_nth(list, 1);
        GtkWidget *bigbox = list->data;
        list = gtk_container_get_children(GTK_CONTAINER(bigbox));
        list = g_list_nth(list, 1);
        gtk_label_set_text(GTK_LABEL(list->data),"Read carefully:\nValues inserted above should be even numbers from range <6,18>");
    }
}

void applyBoardSize(coords c) {
    heigth = c.w;
    if (c.k%2==1) {
        c.k++;
        change1ToRed = 1;
    }
    width = c.k;
    return;
}

void readAndDestroyWindow ()
{
    GtkWidget *child = gtk_bin_get_child(GTK_BIN(window1));
    GList *list = gtk_container_get_children(GTK_CONTAINER(child));
    list = g_list_nth(list, 2);
    GtkWidget *button = list->data;
    hilfe = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button));
    getText1();

    if (message[0]=='1') {
        otherIsReady=1;
        coords c = readInfoProperly(message);
        applyBoardSize(c);
        makeBoard();
    }
    sprintf(message, "2r");
    sendText();
    g_timeout_add(100,getText,NULL);

    if (!otherIsReady){
        gtk_widget_show_all(windowWait);
        gtk_window_set_keep_above(GTK_WINDOW(windowWait), TRUE);
    }
    gtk_widget_destroy(window1);
}




int main(int argc,char *argv[])
{
    if ((streams=initPipes(argc,argv)) == NULL)
        return 1;
    gtk_init(&argc, &argv);


    if (argc == 2 && strcmp(argv[1],"A") == 0) {
        player = 1;
    } else {
        player = 2;
    }

    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window1),"Reversi - options");
    gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window1), 10);

    GtkWidget *boxMain = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window1), boxMain);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(boxMain), box1);

    GtkWidget *frame = gtk_frame_new(NULL);
    GtkWidget *writing = gtk_label_new("\nREVERSI\n");
    gtk_container_add(GTK_CONTAINER(frame), writing);
    gtk_box_pack_start(GTK_BOX(box1), frame, TRUE, TRUE, 20);

    windowWait = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(windowWait),"Hold on...");
    gtk_window_set_position(GTK_WINDOW(windowWait),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(windowWait), 10);
    GtkWidget *boxWait = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(windowWait), boxWait);
    GtkWidget *writingWait = gtk_label_new(NULL);
    gtk_container_add(GTK_CONTAINER(boxWait), writingWait);

    windowEnd = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    if (player==1) {
        gtk_window_set_title(GTK_WINDOW(windowEnd),"Game over - player 1");
    } else {
        gtk_window_set_title(GTK_WINDOW(windowEnd),"Game over - player 2");
    }

    gtk_window_set_position(GTK_WINDOW(windowEnd),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(windowEnd), 10);
    g_signal_connect(G_OBJECT(windowEnd), "destroy",G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *boxMainEnd = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(windowEnd), boxMainEnd);
    GtkWidget *frameEnd = gtk_frame_new(NULL);
    GtkWidget *writingEnd = gtk_label_new(NULL);
    gtk_container_add(GTK_CONTAINER(frameEnd), writingEnd);
    gtk_box_pack_start(GTK_BOX(boxMainEnd), frameEnd, TRUE, TRUE, 20);
    GtkWidget *buttonEnd=gtk_button_new_with_label("Quit game");
    g_signal_connect(G_OBJECT(buttonEnd), "clicked",G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_add(GTK_CONTAINER(boxMainEnd), buttonEnd);



    if (player == 1) {
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

        GtkWidget *option_board_heigth = gtk_label_new("Choose board width:");
        GtkWidget *option_board_width = gtk_label_new("Choose board height:");

        GtkWidget *text1 = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(text1), 100);
        gtk_entry_set_alignment(GTK_ENTRY(text1), 1);
        gtk_entry_set_text(GTK_ENTRY(text1), "8");

        GtkWidget *text2 = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(text2), 100);
        gtk_entry_set_alignment(GTK_ENTRY(text2), 1);
        gtk_entry_set_text(GTK_ENTRY(text2), "8");

        gtk_grid_attach(GTK_GRID(grid), option_board_heigth, 1, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), option_board_width, 1, 2, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), text1, 2, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), text2, 2, 2, 1, 1);

        GtkWidget *checkbox = gtk_check_button_new_with_label("Show possible moves");
        gtk_grid_attach(GTK_GRID(grid), checkbox, 1, 3, 2, 1);

        GtkWidget *checkbox1 = gtk_check_button_new_with_label("Change my discs to red (default black)");
        gtk_grid_attach(GTK_GRID(grid), checkbox1, 1, 4, 2, 1);

        GtkWidget *button = gtk_button_new_with_label("Start game");
        GtkWidget *box3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_box_set_homogeneous(GTK_BOX(box3), TRUE);
        gtk_container_add(GTK_CONTAINER(box2), box3);
        gtk_box_pack_start(GTK_BOX(box3), button, TRUE, FALSE, 10);

        g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(readInfoAndDestroyWindow), NULL);


        GtkWidget *valueInfo = gtk_label_new("Values inserted above should be even numbers from range <6,18>");
        gtk_container_add(GTK_CONTAINER(box3), valueInfo);

        gtk_label_set_text(GTK_LABEL(writingWait),"\nWaiting for player 2 to choose their options\n");

    } else {


        GtkWidget *yoText = gtk_label_new("You're player 2, so you wait for player 1 to choose board properties");
        gtk_container_add(GTK_CONTAINER(boxMain), yoText);

        GtkWidget *checkbox = gtk_check_button_new_with_label("Show possible moves");
        gtk_box_pack_start(GTK_BOX(boxMain), checkbox, TRUE, FALSE, 0);

        GtkWidget *button = gtk_button_new_with_label("Start game");
        gtk_container_add(GTK_CONTAINER(boxMain), button);

        g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(readAndDestroyWindow), NULL);

        gtk_label_set_text(GTK_LABEL(writingWait),"\nWaiting for player 1 to choose their options\n");
    }

    gtk_widget_show_all(window1);


    char name[100];
    sprintf(name, "Reversi - game - player %d", player);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),name);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(surrender), NULL);

    GtkWidget *mainBoxGame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), mainBoxGame);

    GtkWidget *board = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(board), 0);
    gtk_grid_set_row_homogeneous(GTK_GRID(board), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(board), 0);
    gtk_grid_set_column_homogeneous(GTK_GRID(board), TRUE);
    gtk_box_pack_start(GTK_BOX(mainBoxGame), board, TRUE, TRUE, 10);

    GtkWidget *quickEnd = gtk_button_new_with_label("Surrender");
    gtk_box_pack_end(GTK_BOX(mainBoxGame), quickEnd, FALSE, TRUE, 10);
    g_signal_connect(G_OBJECT(quickEnd), "clicked", G_CALLBACK(surrender), window);

    gtk_main();
    return 0;
}


void sendText()
{
    sendStringToPipe(streams, message);
}

gboolean getText(gpointer data)
{
    if (getStringFromPipe(streams,message,20)) {
        if (message[0]=='1' && message[1]=='r' && player==2 && !boardPrepared) {
            boardPrepared = 1;
            coords c = readInfoProperly(message);
            applyBoardSize(c);
            makeBoard();
        }
        if (message[0]=='2' && message[1]=='r' && player==1 && !boardPrepared) {
            boardPrepared = 1;
            makeBoard();
        }
        if (message[0]=='1' && message[1]=='m' && player==2 && whosTurn==1) {
            whosTurn = 2;
            coords c = readInfoAboutAMove(message);
            MakeA1Move(game, c);

            if (can2MakeAMoveAtAll(game, heigth, width)==0) {
                if (can1MakeAMoveAtAll(game, heigth, width)==0) {
                    coords res =  endOfTheGame(game);
                    char s[100];
                    prepareMessage(s, res);
                    appendMessage(s, windowEnd);
                    gtk_widget_show_all(windowEnd);
                } else {
                    whosTurn = 1;
                }
            }

            updateBoard();
        }
        if (message[0]=='2' && message[1]=='m' && player==1 && whosTurn==2) {
            whosTurn = 1;
            coords c = readInfoAboutAMove(message);
            MakeA2Move(game, c);

            if (can1MakeAMoveAtAll(game, heigth, width)==0) {
                if (can2MakeAMoveAtAll(game, heigth, width)==0) {
                    coords res =  endOfTheGame(game);
                    char s[100];
                    prepareMessage(s, res);
                    appendMessage(s, windowEnd);
                    gtk_widget_show_all(windowEnd);
                } else {
                    whosTurn = 2;
                }
            }

            updateBoard();
        }
        if (message[0]=='1' && message[1]=='s') {
            char s[100] = "You won!\nPlayer 1 has surrendered!";
            appendMessage(s, windowEnd);
            gtk_widget_show_all(windowEnd);
        }
        if (message[0]=='2' && message[1]=='s') {
            char s[100] = "You won!\nPlayer 2 has surrendered!";
            appendMessage(s, windowEnd);
            gtk_widget_show_all(windowEnd);
        }
    }

    return TRUE;
}

void getText1() {
    getStringFromPipe(streams,message,20);
}

void surrender(GtkWidget *widget, gpointer data)
{
    if (player==1) {
        sprintf(message, "1s");
    } else {
        sprintf(message, "2s");
    }
    sendText();

    closePipes(streams);
    gtk_main_quit();
}


