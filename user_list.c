/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "user_list.h"
#include "song_list.c"


void createEmptyListU(tListU *L){
    *L=NULLU;
}

bool isEmptyListU(tListU L){
    return L==NULLU;
}

tPosU firstU(tListU L){
    return L;
}

tPosU lastU(tListU L){
    tPosU i;
    for(i=L;i->next!=NULLU;i=i->next);
    return i;
}

tPosU nextU(tPosU p, tListU L){
    return p->next;
}

tPosU previousU(tPosU p, tListU L){
    tPosU i;
    if(p==L){
        return NULLU;
    }
    for(i=L;i->next!=p;i=i->next);
    return i;
}

tItemU getItemU(tPosU p, tListU L){
    return p->data;
}

bool createNode(tPosU *p){
    *p= malloc(sizeof(**p));
    return (*p!=NULLU);
}

bool insertItemU(tItemU d, tListU *L){
    tPosU q,aux;
    if(!createNode(&q)){
        return false;
    }

    memcpy(&q->data,&d,sizeof(d));
    q->next=NULLU;
    if(isEmptyListU(*L)){
            *L=q;
    }else{
        if(strcmp((*L)->data.userName,q->data.userName)>0){
            q->next=*L;
            *L=q;
        }else {
            for (aux = *L; aux->next != NULLU; aux = aux->next) {
                if (strcmp(d.userName, aux->next->data.userName) < 0) {
                    q->next = aux->next;
                    aux->next = q;
                    break;
                    }
                }
                if(aux->next==NULLU){
                    aux->next=q;
              }

            }
        }
        return true;
    }




void deleteAtPositionU(tPosU p,tListU *L) {
    tPosU aux;
    tItemU auxItem;

    if (isEmptyListU(*L)) {
        return;
    }

    if (p == NULLU) {
        for (aux = *L; aux->next != NULLU; aux = aux->next) {
            if (aux->next == p) {
                aux->next = NULLU;
                free(p);
            }
        }
    } else if (p == *L) {
        *L = p->next;
        free(p);
    } else {
        for (aux = *L; aux->next != NULLU; aux = aux->next) {
            if (aux->next == p) {
                auxItem = getItemU(aux, *L);
                deleteListS(&auxItem.songList);
                aux->next = p->next;
                p->next = NULLU;
                free(p);
            }

        }
    }
}



void updateItemU(tItemU d,tPosU p,tListU *L){
    p->data=d;
}

tPosU findItemU(tUserName d,tListU L){
    tPosU aux;
    for(aux= firstU(L);aux!=NULLU && strcmp(d, getItemU(aux,L).userName)<=0;aux=aux->next){
        if(strcmp(aux->data.userName,d)==0){
            return aux;
        }
    }

    return NULLU;
}