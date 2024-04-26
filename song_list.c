/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 26/ 04 / 24
 */

#include "song_list.h"
#include <string.h>
#include <stdlib.h>

void createEmptyListS(tListS *L){
    L->lastPos=NULLS; /*Crea una lista vacia*/
}

bool isEmptyListS(tListS L){
    return L.lastPos == NULLS; /*Determina si la lista está vacía*/
}

tPosS firstS(tListS L){
    return 0; /*Devuelve la posición del primer elemento de la lista*/
}

tPosS lastS(tListS L){
    return L.lastPos; /*Devuelve la posición del último elemento de la lista*/
}

tPosS nextS(tPosS p,tListS L){
    if(p== lastS(L)){/*Si la posición es la última, devuelve nulo*/
        return NULLS;
    }
    else{/*Si no, se pasa a la siguiente posición*/
        return ++p;
    }
}

tPosS previousS(tPosS p,tListS L) {
    if (p == 0) {/*Si la posición es la primera, devuelve nulo*/
        return NULLS;
    }
    else {/*Si no, se vuelve a la posición anterior*/
        return --p;
    }
}

bool insertItemS(tItemS d, tPosS p, tListS *L){
    if(L->lastPos == MAX_SIZE){/*Si la lista está llena, devuelve falso*/
        return false;
    }
    else if(isEmptyListS(*L)||p==NULLS){ /*Si la lista está vacía o la posición es nula*/
        L->lastPos++; /*La última posición aumentará en uno*/
        L->data[L->lastPos]=d; /*Se inserta el elemento en la última posición */
    }
    else{
        L->lastPos++; /*Si no, la última posición aumentará en uno*/
        for(p=L->lastPos;p>=p+1;p--){/*La posicion ira disminuyendo*/
            L->data[p]=L->data[p-1]; /*Los datos de p seran iguales a los de la position anterior*/
        }
        L->data[p]=d;/*Y se insertará el elemento deseado en p*/
    }
    return true;
}

void deleteAtPositionS(tPosS p,tListS *L){
    tPosS q;
    for(q=p;q<L->lastPos;q++){ /*Para la posición p, mientras sea anterior a la última, se irá incrementando*/
        L->data[q]=L->data[q+1]; /*Los datos de la posición q serán iguales a los de la posición siguiente a q*/
    }
    L->lastPos--;/*La última posición disminuirá en uno*/


}

tItemS getItemS(tPosS p,tListS L){
    return L.data[p];/*Devuelve los datos de la posición p*/
}

void updateItemS(tItemS d,tPosS p, tListS *L){
    L->data[p]=d; /*Actualiza el item, introduciendo los nuevos datos del item en la posición p*/
}

tPosS findItemS(tSongTitle d, tListS L){
    tPosS aux;
    if(isEmptyListS(L)){ /*Si la lista está vacía devuelve nulo*/
        return NULLS;
    }
    for(aux=firstS(L);aux<=L.lastPos;aux++){/*Recorre la lista hasta la última posición*/
        if(strcmp(L.data[aux].songTitle,d)==0){/*Compara el título dado con los títulos de las canciones de la lista*/
            return aux;/*Devuelve la posición de la canción si coincide con la indicada*/
        }
    }
}