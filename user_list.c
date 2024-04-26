/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 26/ 04 / 24
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
        if(aux==p){ //Si la posición es la misma que la que se busca devuelve el dato
            return aux->data;
        }
        aux=aux->next; //Pasa a la siguiente posición

    }
}

bool createNode(tPosU *p){
    *p= malloc(sizeof(**p)); //Crea un nodo
    return (*p!=NULLU); //Devuelve verdadero si se ha creado correctamente
}

bool insertItemU(tItemU d, tListU *L){
    tPosU q,aux;
    if(!createNode(&q)){ //Si no se ha podido crear el nodo, devuelve falso
        return false;
    }

    q->data=d;
    q->next=NULLU;
    if(isEmptyListU(*L)){ //Si la lista está vacía, el nodo se inserta en la primera posición
        *L=q;
    }else{
        if(strcmp((*L)->data.userName,q->data.userName)>0){ //Si el nombre de usuario es menor que el de la primera posición, se inserta en la primera posición
            q->next=*L;
            *L=q;
        }else {
            for (aux = *L; aux->next != NULLU; aux = aux->next) { //Recorre la lista
                if (strcmp(d.userName, aux->next->data.userName) < 0) { //Si el nombre de usuario es menor que el de la siguiente posición, se inserta en esa posición
                    q->next = aux->next;
                    aux->next = q;
                    break;
                }
            }
            if(aux->next==NULLU){ //Si no se ha insertado en ninguna posición, se inserta en la última
                aux->next=q;
            }

        }
    }
    return true;
}


void deleteAtPositionU(tPosU p,tListU *L) {
    tPosU aux;
    if (isEmptyListU(*L)) { //Si la lista está vacía, no se puede borrar
        return;
    }

    if (p == NULLU) { //Si la posición es nula
        for (aux = *L; aux->next != NULLU; aux = aux->next) {  //Recorre la lista
            if (aux->next == lastU(*L)) { //Si la siguiente posición es la última, se borra
                free(aux->next);
                aux->next = NULLU;
                break;
            }
        }
    } else if (p == *L) { //Si la posición es la primera, se borra
        tPosU temp = p-> next;
        free(p);
        *L = temp;
    } else {
        for (aux = *L; aux->next != NULLU; aux = aux->next) { //Recorre la lista
            if (aux->next == p) { //Si la siguiente posición es la que se busca, se borra
                tPosU temp = p-> next;
                aux->next = temp;
                break;
            }

        }
    }
}




void updateItemU(tItemU d,tPosU p,tListU *L){
    p->data=d; //Actualiza el item, introduciendo los nuevos datos del item en la posición p
}

tPosU findItemU(tUserName d,tListU L){
    tPosU aux;
    for(aux=firstU(L);aux!=NULLU && strcmp(aux->data.userName,d)!=0;aux=aux->next); //Recorre la lista
    return aux; //Devuelve la posición del elemento
}