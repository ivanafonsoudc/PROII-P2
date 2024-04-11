/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: 2.4
 * DATE: 15 / 02 / 24
 */

#include "song_list.h"
#include <string.h>

void createEmptyListS(tListS *L){
    L->lastPos=NULLS;
}

bool isEmptyListS(tListS L){
    return L.lastPos == NULLS;
}

tPosS firstS(tListS L){
    return 0;
}

tPosS lastS(tListS L){
    return L.lastPos;
}

tPosS nextS(tPosS p,tListS L){
    if(p== lastS(L)){
        return NULLS;
    }
    else{
        return ++p;
    }
}

tPosS previousS(tPosS p,tListS L){
    return --p;
}

bool insertItemS(tItemS d, tPosS p, tListS *L){
    if(L->lastPos == MAX_SIZE){
        return false;
    }
    else if(p==NULLS){
        L->lastPos++;
        L->data[L->lastPos]=d;
    }
    else{
        tPosS i;
        L->lastPos++;
        for(i=L->lastPos;i>=p+1;i--){
            L->data[i]=L->data[i-1];
        }
        L->data[p]=d;
    }
    return true;
}

void deleteAtPositionS(tPosS p,tListS *L){
    tPosS aux;
    L->lastPos--;
    for(aux=p;aux<=L->lastPos;aux++){
        L->data[aux]=L->data[aux+1];
    }
}

tItemS getItemS(tPosS p,tListS L){
    return L.data[p];
}

void updateItemS(tItemS d,tPosS p, tListS *L){
    L->data[p]=d;
}

tPosS findItemS(tSongTitle d, tListS L){
    tPosS aux;
    if(isEmptyListS(L)){
        return NULLS;
    }
    for(aux=firstS(L);aux<=L.lastPos;aux++){
        if(strcmp(L.data[aux].songTitle,d)==0){
            return aux;
        }
    }
    return NULLS;
}

bool deleteListS(tListS *L){
    tPosS aux;
    for(aux= firstS(*L);aux<=L->lastPos;aux++){
        deleteAtPositionS(aux,L);
    }
    if(isEmptyListS(*L)){
        return true;
    }
    else{
        return false;
    }
}