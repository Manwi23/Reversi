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

