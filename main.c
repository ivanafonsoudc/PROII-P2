/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 12/ 04 / 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

int proBasic(char *c){
    int result=strcmp(c,"basic");
    if(result==0){
        return 0;
    }else{
        return 1;
    }
}

char* CategoryToString(tUserCategory cat){
    switch(cat){
        case 0:
            return "basic";
        case 1:
            return "pro";

        default:
            break;
    }
}

void New(tListU *L, tUserName userName, tUserCategory userCategory) {
    tItemU item;
    tPosU pos;

    pos = findItemU(userName,  *L);

    if(pos == NULLU) {
        strcpy(item.userName, userName);
        item.userCategory = userCategory;
        item.totalPlayTime = 0;
        createEmptyListS(&item.songList);
        if(insertItemU(item, L)){
        printf("* New: user %s category %s\n", userName, CategoryToString(userCategory));
        } else {
            printf("+ Error: New not possible\n");
        }
    } else {
        printf("+ Error: New not possible\n");
    }

}

void Delete(tListU *L, tUserName userName) {
    tPosU pos;
    tItemU item;

    pos = findItemU(userName, *L);

    if (pos != NULLU) {
        item = getItemU(pos, *L);
        deleteListS(&item.songList);
        deleteAtPositionU(pos, L);
        printf("* Delete: user %s category %s totalplaytime %d\n", userName, CategoryToString(item.userCategory), item.totalPlayTime);
    } else {
        printf("+ Error: Delete not possible\n");
    }
}

void Add(tListU *L, tUserName userName, tSongTitle songTitle, tPlayTime playTime) {
    tPosU pos;
    tItemU item;
    tItemS song;
    tPosS posS;

    pos = findItemU(userName, *L);

    if (pos != NULLU) {
        item = getItemU(pos, *L);
        strcpy(song.songTitle, songTitle);
        song.playTime = playTime;
        posS = findItemS(songTitle, item.songList);

        if (posS == NULLS) {
            insertItemS(song, lastS(item.songList), &item.songList);
            item.totalPlayTime += playTime;
            updateItemU(item, pos, L);
            printf("Song %s added to user %s.\n", songTitle, userName);
        } else {
            printf("Song %s already exists in user %s.\n", songTitle, userName);
        }
    } else {
        printf("User %s not found.\n", userName);
    }
}

void Upgrade(tListU *L, tUserName userName) {
    tPosU pos;
    tItemU item;

    pos = findItemU(userName, *L);

    if(pos!=NULLU && getItemU(pos, *L).userCategory==0) {
        item = getItemU(pos, *L);
        item.userCategory++;
        updateItemU(item, pos, L);
        printf("* Upgrade: user %s category %s\n", userName, CategoryToString(item.userCategory));
    } else {
        printf("+ Error: Upgrade not possible\n");
    }
}

void Play(tListU *L, tUserName userName, tSongTitle songTitle, tPlayTime playTime) {

    tPosU pos;
    tItemU item;
    tItemS song;
    tPosS posS;

    pos = findItemU(userName, *L);

    if (pos != NULLU) {
        item = getItemU(pos, *L);
        strcpy(song.songTitle, songTitle);
        song.playTime = playTime;
        posS = findItemS(songTitle, item.songList);

        if (posS != NULLS) {
            item.totalPlayTime += playTime;
            updateItemU(item, pos, L);
            printf("* Add: user %s adds song %s\n", userName, songTitle);
        } else {
            printf("+ Error: Play not possible\n");
        }
    } else {
        printf("+ Error: Play not possible\n");
    }
}

void Stats(tListU *L) {
    tPosU p;
    tItemU d;
    int basic = 0, pro = 0, basicPlays = 0, proPlays = 0;

    for (p=firstU(*L); p != NULLU; p = nextU(p, *L)) {
        d = getItemU(p, *L);

        printf("User %s category %s totalplaytime %d\n", d.userName, CategoryToString(d.userCategory), d.totalPlayTime);

        if (d.userCategory == 0) {
            basic++;
            basicPlays += d.totalPlayTime;
        } else {
            pro++;
            proPlays += d.totalPlayTime;
        }

        if(isEmptyListS(d.songList)){
            printf("No songs\n");
        } else {
            tPosS pS;
            tItemS dS;
            for (pS = firstS(d.songList); pS != NULLS; pS = nextS(pS, d.songList)) {
                dS = getItemS(pS, d.songList);
                printf("Song %s playtime %d\n", dS.songTitle, dS.playTime);
            }
        }
    }

    printf("\nCategory  Users  TimePlay  Average\n");
    printf("Basic\t  %d\t %d \t   %.2f\n", basic, basicPlays, (float)basicPlays / (float)basic);
    printf("Pro\t  %d\t %d \t   %.2f\n", pro, proPlays, (float)proPlays / (float)pro);
}

void Remove(tListU *L, tPlayTime maxTime) {
    tPosU p;
    tItemU d;
    tPosS pS;
    tItemS dS;

    for (p = firstU(*L); p != NULLU; p = nextU(p, *L)) {
        d = getItemU(p, *L);
        for (pS = firstS(d.songList); pS != NULLS; pS = nextS(pS, d.songList)) {
            dS = getItemS(pS, d.songList);
            if (dS.playTime > maxTime) {
                deleteAtPositionS(pS, &d.songList);
                d.totalPlayTime -= dS.playTime;
                updateItemU(d, p, L);
            }
        }
    }
}



void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListU *L) {
    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            New(L, param1, proBasic(param2));
            break;
        case 'D':
            printf("%s %c: user %s\n", commandNumber, command, param1);
            Delete(L, param1);
            break;
        case 'A':
            printf("%s %c: user %s song %s \n", commandNumber, command, param1, param2);
            Add(L, param1, param2, atoi(param3));
            break;
        case 'U':
            printf("%s %c: user %s\n", commandNumber, command, param1);
            Upgrade(L, param1);
            break;
        case 'P':
            printf("%s %c: user %s song %s minutes %s\n", commandNumber, command, param1, param2, param3);
            Play(L, param1, param2, atoi(param3));
            break;
        case 'S':
            printf("%s %c:\n", commandNumber, command);
            Stats(L);
            break;
        case 'R':
            printf("%s %c: maxtime %s\n", commandNumber, command, param2);
            Remove(L, atoi(param2));
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    tListU L;
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "play.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}
