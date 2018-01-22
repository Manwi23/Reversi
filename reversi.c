#include "reversi.h"


int can1MakeAMove (int tab[][20], int a, int b) {
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

        if (bp>0) {
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


int can2MakeAMove (int tab[][20], int a, int b) {
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

        if (bp>0) {
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


void MakeA1Move (int tab[][20], int a, int b) {
    printf("I was called to make a move\n");
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

        if (bp>0) {
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
                    while (bp>0 && ap>0) {
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

void MakeA2Move (int tab[][20], int a, int b) {
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

        if (bp>0) {
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
                    while (bp>0 && ap>0) {
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
