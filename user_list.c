/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 12/ 04 / 24
 */

#include "user_list.h"


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
                aux->next = p->next;
                free(p);
                break;
            }

        }
    }
}



void updateItemU(tItemU d,tPosU p,tListU *L){
    p->data=d;
}

tPosU findItemU(tUserName d,tListU L){
    tPosU aux;
    for(aux= firstU(L);aux!=NULLU;aux=aux->next){
        if(strcmp(aux->data.userName,d)==0){
            return aux;
        }
    }

    return NULLU;
}