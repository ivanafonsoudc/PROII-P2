/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 12/ 04 / 24
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "song_list.h"

#define NULLU NULL

typedef struct tItemU {
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
} tItemU;




typedef struct tNode *tPosU;

struct tNode{
    tItemU data;
    tPosU next;
};

typedef tPosU tListU;

void createEmptyListU(tListU *L);
bool isEmptyListU(tListU L);
tPosU firstU(tListU L);
tPosU lastU(tListU L);
tPosU nextU(tPosU p, tListU L);
tPosU previousU(tPosU p, tListU L);
bool insertItemU(tItemU d, tListU *L);
void deleteAtPositionU(tPosU p,tListU *L);
tItemU getItemU(tPosU p,tListU L);
void updateItemU(tItemU d,tPosU p,tListU *L);
tPosU findItemU(tUserName d,tListU L);



#endif
