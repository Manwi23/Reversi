#include "reversi.h"


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
                    while (bp>0 && ap>0 && czyRuch) {
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
                    while (ap<19 && bp<19) {
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
                    while (bp>0 && ap>0 && czyRuch) {
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
    if (message[4]!='s') {
        th[1]=message[4];
    }
    c.w = atoi(th);
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
    c.k=atoi(th);
    return c;
}

int can2MakeAMoveAtAll(int tab[][20], int wys, int szer) {
    int b = 0;
    coords c;
    for (c.w=0; c.w<wys && !b; c.w++) {
        for (c.k=0; c.k<szer && !b; c.k++) {
            if (can2MakeAMove(tab, c)) {
                b=1;
            }
        }
    }
    return b;
}

int can1MakeAMoveAtAll(int tab[][20], int wys, int szer) {
    int b = 0;
    coords c;
    for (c.w=0; c.w<wys && !b; c.w++) {
        for (c.k=0; c.k<szer && !b; c.k++) {
            if (can1MakeAMove(tab, c)) {
                b=1;
            }
        }
    }
    return b;
}

coords endOfTheGame(int tab[][20]) {
    printf("Koniec gry\n");
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


void appendMessage(char s[], GtkWidget *windowEnd) {
    GtkWidget *box = gtk_bin_get_child(GTK_BIN(windowEnd));
    GList *list = gtk_container_get_children(GTK_CONTAINER(box));
    list = gtk_container_get_children(GTK_CONTAINER(list->data));
    gtk_label_set_text(GTK_LABEL(list->data),s);
    return;
}
