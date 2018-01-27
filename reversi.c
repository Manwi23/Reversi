#include "reversi.h"

gchar nn[100] = "";


int can1MakeAMove (int tab[][20], coords c) {
    int a = c.w;
    int b = c.k;
    int czyRuch = 0;
    int ap = a;
    int bp = b;
    if (tab[a][b]==0) {
        if (a>1) {
            if (tab[a-1][b]==2) {
                ap = a;
                bp = b;
                while (ap>0) {
                    if (tab[ap-1][bp]==2) {
                        ap--;
                    } else if (tab[ap-1][bp]==1) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (b<19) {
                ap = a;
                bp = b;
                if (tab[ap-1][bp+1]==2){
                    while (ap>0 && bp<19) {
                        if (tab[ap-1][bp+1]==2) {
                            ap--;
                            bp++;
                        } else if (tab[ap-1][bp+1]==1) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b<19) {
            if (tab[a][b+1]==2){
                ap = a;
                bp = b;
                while (bp<19) {
                    if (tab[ap][bp+1]==2) {
                        bp++;
                    } else if (tab[ap][bp+1]==1) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (a<19) {
                ap = a;
                bp = b;
                if (tab[ap+1][bp+1]==2){
                    while (ap<19 && bp<19) {
                        if (tab[ap+1][bp+1]==2) {
                            ap++;
                            bp++;
                        } else if (tab[ap+1][bp+1]==1) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (a<19) {
            ap = a;
            bp = b;
            if (tab[ap+1][bp]==2){
                while (ap<19) {
                    if (tab[ap+1][bp]==2) {
                        ap++;
                    } else if (tab[ap+1][bp]==1) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (b>0) {
                ap = a;
                bp = b;
                if (tab[ap+1][bp-1]==2){
                    while (ap<19 && bp>0) {
                        if (tab[ap+1][bp-1]==2) {
                            ap++;
                            bp--;
                        } else if (tab[ap+1][bp-1]==1) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b>0) {
            ap = a;
            bp = b;
            if (tab[ap][bp-1]==2){
                while (bp>0) {
                    if (tab[ap][bp-1]==2) {
                        bp--;
                    } else if (tab[ap][bp-1]==1) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (a>0) {
                ap = a;
                bp = b;
                if (tab[ap-1][bp-1]==2){
                    while (bp>0 && ap>0) {
                        if (tab[ap-1][bp-1]==2) {
                            ap--;
                            bp--;
                        } else if (tab[ap-1][bp-1]==1) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    return czyRuch;
}


int can2MakeAMove (int tab[][20], coords c) {
    int a = c.w;
    int b = c.k;
    int czyRuch = 0;
    int ap = a;
    int bp = b;
    if (tab[a][b]==0) {
        if (a>1) {
            if (tab[a-1][b]==1) {
                ap = a;
                bp = b;
                while (ap>0) {
                    if (tab[ap-1][bp]==1) {
                        ap--;
                    } else if (tab[ap-1][bp]==2) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (b<19) {
                ap = a;
                bp = b;
                if (tab[ap-1][bp+1]==1){
                    while (ap>0 && bp<19) {
                        if (tab[ap-1][bp+1]==1) {
                            ap--;
                            bp++;
                        } else if (tab[ap-1][bp+1]==2) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b<19) {
            if (tab[a][b+1]==1){
                ap = a;
                bp = b;
                while (bp<19) {
                    if (tab[ap][bp+1]==1) {
                        bp++;
                    } else if (tab[ap][bp+1]==2) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (a<19) {
                ap = a;
                bp = b;
                if (tab[ap+1][bp+1]==1){
                    while (ap<19 && bp<19) {
                        if (tab[ap+1][bp+1]==1) {
                            ap++;
                            bp++;
                        } else if (tab[ap+1][bp+1]==2) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (a<19) {
            ap = a;
            bp = b;
            if (tab[ap+1][bp]==1){
                while (ap<19) {
                    if (tab[ap+1][bp]==1) {
                        ap++;
                    } else if (tab[ap+1][bp]==2) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (b>0) {
                ap = a;
                bp = b;
                if (tab[ap+1][bp-1]==1){
                    while (ap<19 && bp>0) {
                        if (tab[ap+1][bp-1]==1) {
                            ap++;
                            bp--;
                        } else if (tab[ap+1][bp-1]==2) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b>0) {
            ap = a;
            bp = b;
            if (tab[ap][bp-1]==1){
                while (bp>0) {
                    if (tab[ap][bp-1]==1) {
                        bp--;
                    } else if (tab[ap][bp-1]==2) {
                        czyRuch = 1;
                        return czyRuch;
                    } else {
                        break;
                    }
                }
            }
            if (a>0) {
                ap = a;
                bp = b;
                if (tab[ap-1][bp-1]==1){
                    while (bp>0 && ap>0) {
                        if (tab[ap-1][bp-1]==1) {
                            ap--;
                            bp--;
                        } else if (tab[ap-1][bp-1]==2) {
                            czyRuch = 1;
                            return czyRuch;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    return czyRuch;
}


coords readWhere (const char *name) {
    coords c;
    int t;
    c.w = name[0]-'0';
    if (name[1]==',') {
        c.k = name[2]-'0';
        if (name[3]!='\0') {
            t = name[3]-'0';
            c.k = 10*c.k + t;
        }
    } else {
        t = name[1]-'0';
        c.w = 10*c.w + t;
        c.k = name[3]-'0';
        if (name[4]!='\0') {
            t = name[4]-'0';
            c.k = 10*c.k + t;
        }
    }
    return c;
}


void MakeA1Move (int tab[][20], coords c) {
    int a = c.w;
    int b = c.k;
    tab[a][b]=1;
    int czyRuch = 0;
    int ap = a;
    int bp = b;
    if (tab[a][b]==1) {
        if (a>1) {
            if (tab[a-1][b]==2) {
                czyRuch=0;
                ap = a;
                bp = b;
                while (ap>0) {
                    if (tab[ap-1][bp]==2) {
                        ap--;
                    } else if (tab[ap-1][bp]==1) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (ap>0 && czyRuch==1) {
                    if (tab[ap-1][bp]==2) {
                        tab[ap-1][bp]=1;
                        ap--;
                    } else {
                        break;
                    }
                }
            }
            if (b<19) {
                ap = a;
                bp = b;
                if (tab[ap-1][bp+1]==2){
                    czyRuch = 0;
                    while (ap>0 && bp<19) {
                        if (tab[ap-1][bp+1]==2) {
                            ap--;
                            bp++;
                        } else if (tab[ap-1][bp+1]==1) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (ap>0 && bp<19 && czyRuch==1) {
                        if (tab[ap-1][bp+1]==2) {
                            tab[ap-1][bp+1]=1;
                            ap--;
                            bp++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b<19) {
            if (tab[a][b+1]==2){
                czyRuch = 0;
                ap = a;
                bp = b;
                while (bp<19) {
                    if (tab[ap][bp+1]==2) {
                        bp++;
                    } else if (tab[ap][bp+1]==1) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (bp<19 && czyRuch==1) {
                    if (tab[ap][bp+1]==2) {
                        tab[ap][bp+1]=1;
                        bp++;
                    } else {
                        break;
                    }
                }
            }
            if (a<19) {
                czyRuch = 0;
                ap = a;
                bp = b;
                if (tab[ap+1][bp+1]==2){
                    while (ap<19 && bp<19) {
                        if (tab[ap+1][bp+1]==2) {
                            ap++;
                            bp++;
                        } else if (tab[ap+1][bp+1]==1) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (ap<19 && bp<19 && czyRuch==1) {
                        if (tab[ap+1][bp+1]==2) {
                            tab[ap+1][bp+1]=1;
                            ap++;
                            bp++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (a<19) {
            ap = a;
            bp = b;
            if (tab[ap+1][bp]==2){
                czyRuch = 0;
                while (ap<19) {
                    if (tab[ap+1][bp]==2) {
                        ap++;
                    } else if (tab[ap+1][bp]==1) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (ap<19 && czyRuch==1) {
                    if (tab[ap+1][bp]==2) {
                        tab[ap+1][bp]=1;
                        ap++;
                    } else {
                        break;
                    }
                }
            }
            if (b>0) {
                ap = a;
                bp = b;
                czyRuch = 0;
                if (tab[ap+1][bp-1]==2){
                    while (ap<19 && bp>0) {
                        if (tab[ap+1][bp-1]==2) {
                            ap++;
                            bp--;
                        } else if (tab[ap+1][bp-1]==1) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (ap<19 && bp>0 && czyRuch==1) {
                        if (tab[ap+1][bp-1]==2) {
                            tab[ap+1][bp-1]=1;
                            ap++;
                            bp--;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b>0) {
            ap = a;
            bp = b;
            czyRuch = 0;
            if (tab[ap][bp-1]==2){
                while (bp>0) {
                    if (tab[ap][bp-1]==2) {
                        bp--;
                    } else if (tab[ap][bp-1]==1) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (bp>0 && czyRuch==1) {
                    if (tab[ap][bp-1]==2) {
                        tab[ap][bp-1]=1;
                        bp--;
                    } else {
                        break;
                    }
                }
            }
            if (a>0) {
                ap = a;
                bp = b;
                czyRuch = 0;
                if (tab[ap-1][bp-1]==2){
                    while (bp>0 && ap>0) {
                        if (tab[ap-1][bp-1]==2) {
                            ap--;
                            bp--;
                        } else if (tab[ap-1][bp-1]==1) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (bp>0 && ap>0 && czyRuch==1) {
                        if (tab[ap-1][bp-1]==2) {
                            tab[ap-1][bp-1]=1;
                            ap--;
                            bp--;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    return;
}

void MakeA2Move (int tab[][20], coords c) {
    int a = c.w;
    int b = c.k;
    tab[a][b]=2;
    int czyRuch = 0;
    int ap = a;
    int bp = b;
    if (tab[a][b]==2) {
        if (a>1) {
            if (tab[a-1][b]==1) {
                czyRuch=0;
                ap = a;
                bp = b;
                while (ap>0) {
                    if (tab[ap-1][bp]==1) {
                        ap--;
                    } else if (tab[ap-1][bp]==2) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (ap>0 && czyRuch==1) {
                    if (tab[ap-1][bp]==1) {
                        tab[ap-1][bp]=2;
                        ap--;
                    } else {
                        break;
                    }
                }
            }
            if (b<19) {
                ap = a;
                bp = b;
                if (tab[ap-1][bp+1]==1){
                    czyRuch = 0;
                    while (ap>0 && bp<19) {
                        if (tab[ap-1][bp+1]==1) {
                            ap--;
                            bp++;
                        } else if (tab[ap-1][bp+1]==2) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (ap>0 && bp<19 && czyRuch==1) {
                        if (tab[ap-1][bp+1]==1) {
                            tab[ap-1][bp+1]=2;
                            ap--;
                            bp++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b<19) {
            if (tab[a][b+1]==1){
                czyRuch = 0;
                ap = a;
                bp = b;
                while (bp<19) {
                    if (tab[ap][bp+1]==1) {
                        bp++;
                    } else if (tab[ap][bp+1]==2) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (bp<19 && czyRuch==1) {
                    if (tab[ap][bp+1]==1) {
                        tab[ap][bp+1]=2;
                        bp++;
                    } else {
                        break;
                    }
                }
            }
            if (a<19) {
                czyRuch = 0;
                ap = a;
                bp = b;
                if (tab[ap+1][bp+1]==1){
                    while (ap<19 && bp<19) {
                        if (tab[ap+1][bp+1]==1) {
                            ap++;
                            bp++;
                        } else if (tab[ap+1][bp+1]==2) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (ap<19 && bp<19 && czyRuch==1) {
                        if (tab[ap+1][bp+1]==1) {
                            tab[ap+1][bp+1]=2;
                            ap++;
                            bp++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (a<19) {
            ap = a;
            bp = b;
            czyRuch = 0;
            if (tab[ap+1][bp]==1){
                while (ap<19) {
                    if (tab[ap+1][bp]==1) {
                        ap++;
                    } else if (tab[ap+1][bp]==2) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (ap<19 && czyRuch==1) {
                    if (tab[ap+1][bp]==1) {
                        tab[ap+1][bp]=2;
                        ap++;
                    } else {
                        break;
                    }
                }
            }
            if (b>0) {
                ap = a;
                bp = b;
                czyRuch = 0;
                if (tab[ap+1][bp-1]==1){
                    while (ap<19 && bp>0) {
                        if (tab[ap+1][bp-1]==1) {
                            ap++;
                            bp--;
                        } else if (tab[ap+1][bp-1]==2) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (ap<19 && bp>0 && czyRuch==1) {
                        if (tab[ap+1][bp-1]==1) {
                            tab[ap+1][bp-1]=2;
                            ap++;
                            bp--;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        if (b>0) {
            ap = a;
            bp = b;
            czyRuch = 0;
            if (tab[ap][bp-1]==1){
                while (bp>0) {
                    if (tab[ap][bp-1]==1) {
                        bp--;
                    } else if (tab[ap][bp-1]==2) {
                        czyRuch = 1;
                        break;
                    } else {
                        break;
                    }
                }
                ap = a;
                bp = b;
                while (bp>0 && czyRuch==1) {
                    if (tab[ap][bp-1]==1) {
                        tab[ap][bp-1]=2;
                        bp--;
                    } else {
                        break;
                    }
                }
            }
            if (a>0) {
                ap = a;
                bp = b;
                czyRuch = 0;
                if (tab[ap-1][bp-1]==1){
                    while (bp>0 && ap>0) {
                        if (tab[ap-1][bp-1]==1) {
                            ap--;
                            bp--;
                        } else if (tab[ap-1][bp-1]==2) {
                            czyRuch = 1;
                            break;
                        } else {
                            break;
                        }
                    }
                    ap = a;
                    bp = b;
                    while (bp>0 && ap>0 && czyRuch==1) {
                        if (tab[ap-1][bp-1]==1) {
                            tab[ap-1][bp-1]=2;
                            ap--;
                            bp--;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    return;
}

coords readInfoAboutAMove(char message[]){
    coords c;
    char th[2];
    th[0]=message[3];
    if (message[4]!='w') {
        th[1]=message[4];
    }
    c.w = atoi(th);
    if (message[5]!='w') {
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
    c.k=atoi(th);
    return c;
}


int can2MakeAMoveAtAll(int tab[][20], int heigth, int width) {
    int b = 0;
    coords c;
    for (c.w=0; c.w<heigth && !b; c.w++) {
        for (c.k=0; c.k<width && !b; c.k++) {
            if (can2MakeAMove(tab, c)) {
                b=1;
            }
        }
    }
    return b;
}

int can1MakeAMoveAtAll(int tab[][20], int heigth, int width) {
    int b = 0;
    coords c;
    for (c.w=0; c.w<heigth && !b; c.w++) {
        for (c.k=0; c.k<width && !b; c.k++) {
            if (can1MakeAMove(tab, c)) {
                b=1;
            }
        }
    }
    return b;
}

coords endOfTheGame(int tab[][20]) {
    coords c;
    c.w=0;
    c.k=0;
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            if (tab[i][j]==1) {
                c.w++;
            } else if (tab[i][j]==2) {
                c.k++;
            }
        }
    }
    return c;
}


void prepareMessage(char s[], coords res) {
    if (res.w>res.k) {
        sprintf(s, "Game over!\nPlayer 1 won with %d discs, player 2 came second with %d discs.", res.w, res.k);
    } else if (res.k>res.w) {
        sprintf(s, "Game over!\nPlayer 2 won with %d discs, player 1 came second with %d discs.", res.k, res.w);
    } else {
        sprintf(s, "Game over!\nIt's a draw! Each player has %d discs.", res.w);
    }
    return;
}


void appendMessage(char s[], GtkWidget *windowEnd, int type) {
    GtkWidget *box = gtk_bin_get_child(GTK_BIN(windowEnd));
    GList *list = gtk_container_get_children(GTK_CONTAINER(box));
    GList *list1 = gtk_container_get_children(GTK_CONTAINER(list->data));
    gtk_label_set_text(GTK_LABEL(list1->data),s);
    if (type==1) {
        GList *list2 = g_list_nth(list, 2);
        gtk_widget_destroy(GTK_WIDGET(list2->data));
    }
}


void appendDisc(int type, GtkWidget *board, int i, int j, int imgSize) {
    GtkWidget *pp = gtk_grid_get_child_at(GTK_GRID(board), i, j);
    GList *list = gtk_container_get_children(GTK_CONTAINER(pp));
    list = g_list_nth(list, 0);
    pp = list->data;
    list = gtk_container_get_children(GTK_CONTAINER(list->data));
    list = g_list_nth(list, 0);
    gtk_widget_destroy(list->data);
    GdkPixbuf *pixbuf;
    if (type==1) {
        pixbuf = gdk_pixbuf_new_from_file("black.png", NULL);
    } else if (type==2) {
        pixbuf = gdk_pixbuf_new_from_file("red.png", NULL);
    } else if (type==3) {
        pixbuf = gdk_pixbuf_new_from_file("bluesmall.png", NULL);
    } else {
        pixbuf = gdk_pixbuf_new_from_file("blank.png", NULL);
    }
    GdkPixbuf *newpixbuf = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), imgSize, imgSize, GDK_INTERP_NEAREST);
    GtkWidget *image = gtk_image_new_from_pixbuf(GDK_PIXBUF(newpixbuf));
    gtk_container_add(GTK_CONTAINER(pp), image);
    return;
}

void getName(gchar nname[]) {
    strcpy(nname, nn);
    return;
}

void checkNames(int player, gchar myName[], gchar hisName[]) {
    if (strcmp(myName, hisName)==0) {
        gchar s[100]="";
        sprintf(s, " (player %d)", player);
        strcat(myName, s);
        if (player==1) {
            player=2;
        } else {
            player=1;
        }
        sprintf(s, " (player %d)", player);
        strcat(hisName, s);
    }
    return;
}

coords readInfoProperly(gchar message[]) {
    int change =0;
    coords c;
    char th[2];
    th[0]=message[3];
    if (message[4]!='w') {
        th[1]=message[4];
    }
    c.w = atoi(th);
    if (message[5]!='w') {
        th[0]=message[5];
        if (message[6]!='k') {
            th[1]=message[6];
            change = message[8]-'0';
            strcpy(nn, message+9);
        } else {
            th[1]='\0';
            change = message[7]-'0';
            strcpy(nn, message+8);
        }
    } else {
        th[0]=message[6];
        if (message[7]!='k') {
            th[1]=message[7];
            change = message[9]-'0';
            strcpy(nn, message+10);
        } else {
            change = message[8]-'0';
            strcpy(nn, message+9);
            th[1]='\0';
        }
    }
    c.k=atoi(th);
    if (change==1) {
        c.k--;
    }
    return c;
}



void appendHints(GtkWidget *board, int heigth, int width, int game[][20], int imgSize) {
    coords c;
    for (int i=0; i<heigth; i++) {
        for (int j=0; j<width; j++) {
            c.w = i;
            c.k = j;
            if (can1MakeAMove(game, c)) {
                GtkWidget *pp = gtk_grid_get_child_at(GTK_GRID(board), i, j);
                GList *list = gtk_container_get_children(GTK_CONTAINER(pp));
                list = g_list_nth(list, 0);
                pp = list->data;
                list = gtk_container_get_children(GTK_CONTAINER(list->data));
                list = g_list_nth(list, 0);
                gtk_widget_destroy(list->data);
                GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("bluesmall.png", NULL);
                GdkPixbuf *newpixbuf = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), imgSize, imgSize, GDK_INTERP_NEAREST);
                GtkWidget *image = gtk_image_new_from_pixbuf(GDK_PIXBUF(newpixbuf));
                gtk_container_add(GTK_CONTAINER(pp), image);
            }
        }
    }
    return;
}


void destroyNewGameButton(GtkWidget *window) {
    GtkWidget *box = gtk_bin_get_child(GTK_BIN(window));
    GList *list = gtk_container_get_children(GTK_CONTAINER(box));
    GList *list1 = g_list_nth(list, 1);
    gtk_widget_hide(list1->data);
    GList *list2 = g_list_nth(list, 2);
    gtk_widget_destroy(list2->data);
    list = g_list_nth(list, 3);
    GtkWidget *text = list->data;
    gtk_label_set_text(GTK_LABEL(text), "The other player has left the game.");
    gtk_widget_show_all(window);
}

void clearBoard(int heigth, int width, gboolean change, int game[][20]) {
    for (int i=0; i<heigth; i++) {
        for (int j=0; j<width; j++) {
            if (((i+1)*2==heigth && (j+1)*2==width) || (i*2==heigth && j*2==width)) {
                if (change) {
                    game[i][j] = 2;
                } else {
                    game[i][j] = 1;
                }
            } else if ((i*2==heigth && (j+1)*2==width) || ((i+1)*2==heigth && j*2==width)) {
                if (change) {
                    game[i][j] = 1;
                } else {
                    game[i][j] = 2;
                }
            } else {
                game[i][j] = 0;
            }
        }
    }
}

void appendWaitingInfo(GtkWidget *window) {
    GtkWidget *box = gtk_bin_get_child(GTK_BIN(window));
    GList *list = gtk_container_get_children(GTK_CONTAINER(box));
    GList *list1 = g_list_nth(list, 1);
    gtk_widget_hide(list1->data);
    GList *list2 = g_list_nth(list, 2);
    list = g_list_nth(list, 3);
    GtkWidget *text = list->data;
    gtk_label_set_text(GTK_LABEL(text), "Waiting for the other player to accept a new game");
    gtk_widget_show_all(window);
    gtk_widget_hide(list2->data);
}

void appendWantingInfo(GtkWidget *window) {
    GtkWidget *box = gtk_bin_get_child(GTK_BIN(window));
    GList *list = gtk_container_get_children(GTK_CONTAINER(box));
    list = g_list_nth(list, 3);
    GtkWidget *text = list->data;
    gtk_label_set_text(GTK_LABEL(text), "The other player is ready for a new game");
    gtk_widget_show_all(window);
}

void renewWaitingInfo(GtkWidget *window) {
    GtkWidget *box = gtk_bin_get_child(GTK_BIN(window));
    GList *list = gtk_container_get_children(GTK_CONTAINER(box));
    GList *list1 = g_list_nth(list, 1);
    gtk_widget_show(list1->data);
    GList *list2 = g_list_nth(list, 2);
    gtk_widget_show(list2->data);
    list = g_list_nth(list, 3);
    GtkWidget *text = list->data;
    gtk_label_set_text(GTK_LABEL(text), "Cool game!");
    gtk_widget_hide(window);
}


int setImgSize(int heigth, int width) {
    GdkDisplay *display = gdk_display_get_default();
    GdkMonitor *monitor = gdk_display_get_monitor_at_point(display, 0, 0);
    GdkRectangle geo;
    gdk_monitor_get_geometry(monitor, &geo);
    int temp_w = geo.width/2 * 7 / 10;
    int temp_h = geo.height * 6 / 10;
    int pro1 = temp_w / width;
    int pro2 = temp_h / heigth;
    if (pro1<pro2) {
        return pro1;
    } else {
        return pro2;
    }
}
