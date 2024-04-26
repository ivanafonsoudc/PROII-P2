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
    *L=NULLU; //Crea una lista vacia
}

bool isEmptyListU(tListU L){
    return L==NULLU; //Determina si la lista está vacía
}

tPosU firstU(tListU L){
    return L; //Devuelve la posición del primer elemento de la lista
}

tPosU lastU(tListU L){
    tPosU p;
    for(p=L;p->next!=NULLU;p=p->next); //Recorre la lista hasta que el siguiente sea NULLU
    return p; //Devuelve la posición del último elemento
}

tPosU nextU(tPosU p, tListU L){
    return p->next; //Devuelve la posición del siguiente elemento
}

tPosU previousU(tPosU p, tListU L){
    tPosU i;
    if(p==L){ //Si la posición es la primera, devuelve NULLU
        return NULLU;
    }
    for(i=L;i->next!=p;i=i->next); //Recorre la lista hasta que el siguiente sea p
    return i;  //Devuelve la posición anterior
}

tItemU getItemU(tPosU p, tListU L){
    tPosU aux=L;
    while(aux!=NULLU){ //Recorre la lista
        if(aux==p){ //Si la posición es la misma que la que se busca
            return aux->data;
        }
        aux=aux->next;

    }
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

    q->data=d;
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
            if (aux->next == lastU(*L)) {
                free(aux->next);
                aux->next = NULLU;
                break;
            }
        }
    } else if (p == *L) {
        tPosU temp = p-> next;
        free(p);
        *L = temp;
    } else {
        for (aux = *L; aux->next != NULLU; aux = aux->next) {
            if (aux->next == p) {
                tPosU temp = p-> next;
                aux->next = temp;
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
    for(aux=firstU(L);aux!=NULLU && strcmp(aux->data.userName,d)!=0;aux=aux->next);
    return aux;
}