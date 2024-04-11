/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: 2.4
 * DATE: 15 / 02 / 24
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#define NULLS -1
#define MAX_SIZE 25


#include "types.h"

typedef struct tItemS{
    tSongTitle songTitle;
    tPlayTime playTime;
} tItemS;

typedef int tPosS;

typedef struct tListS{
    tPosS lastPos;
    tItemS data[MAX_SIZE];
}tListS;

void createEmptyListS(tListS *L);
bool isEmptyListS(tListS L);
tPosS firstS(tListS L);
tPosS lastS(tListS L);
tPosS nextS(tPosS p, tListS L);
tPosS previousS(tPosS p, tListS L);
bool insertItemS(tItemS d,tPosS p, tListS *L);
void deleteAtPositionS(tPosS p,tListS *L);
tItemS getItemS(tPosS p,tListS L);
void updateItemS(tItemS d,tPosS p,tListS *L);
tPosS findItemS(tUserName d,tListS L);
bool deleteListS(tListS *L);





#endif
