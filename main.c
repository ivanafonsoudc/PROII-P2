/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 26/ 04 / 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

int proBasic(char *c){ //Función que devuelve 0 si es basic y 1 si es pro
    int result=strcmp(c,"basic");
    if(result==0){
        return 0;
    }else{
        return 1;
    }
}

char* CategoryToString(tUserCategory cat){ //Función que devuelve el nombre de la categoría del usuario
    switch(cat){
        case 0:
            return "basic";
        case 1:
            return "pro";

        default:
            break;
    }
}

void deleteListS(tListS *L){ //Función que elimina la lista de canciones
    if(isEmptyListS(*L)){ //Si la lista esta vacía no hace nada
        return;
    }else{
        tPosS aux;
        for(aux= firstS(*L);aux<=L->lastPos;aux++){ //Recorre la lista de canciones
            deleteAtPositionS(aux,L); //Elimina la canción
        }
    }
}


void New(tListU *L, tUserName userName, tUserCategory userCategory) {
    /* Objetivo: Añadir un nuevo usuario a la lista de usuarios.
     * Entrada:
     *     L: Lista de usuarios.
     *     userName: Nombre del usuario.
     *     userCategory: Categoría del usuario.
     * Salida: La lista de usuarios con el nuevo usuario añadido.
     * Precondición: La lista de usuarios ha sido creada.
     * Postcondición: La lista de usuarios contiene un nuevo usuario con el nombre y categoría indicados.
     */
    tItemU item;
    tPosU pos;

    pos = findItemU(userName,  *L); //Busca si el usuario ya existe

    if(pos == NULLU) {
        strcpy(item.userName, userName); //Copia el nombre del usuario
        item.userCategory = userCategory; //Copia la categoría del usuario
        item.totalPlayTime = 0; //Inicializa el tiempo total de reproducción a 0
        createEmptyListS(&item.songList); //Crea una lista de canciones vacía
        if(insertItemU(item, L)){ //Inserta el usuario en la lista
            printf("* New: user %s category %s\n", userName, CategoryToString(userCategory));
        } else {
            printf("+ Error: New not possible\n");
        }
    } else {
        printf("+ Error: New not possible\n");
    }

}

void Delete(tListU *L, tUserName userName) {
    /* Objetivo: Eliminar un usuario de la lista de usuarios.
     * Entrada:
     *     L: Lista de usuarios.
     *     userName: Nombre del usuario.
     * Salida: La lista de usuarios sin el usuario con el nombre indicado.
     * Precondición: La lista de usuarios ha sido creada.
     * Postcondición: La lista de usuarios no contiene el usuario con el nombre indicado.
     */
    tPosU pos;
    tItemU item;

    pos = findItemU(userName, *L); //Busca el usuario

    if(isEmptyListU(*L)){ //Si la lista esta vacia no hace nada
        printf("+ Error: Delete not possible\n");
        return;
    }

    if (pos != NULLU) { //Si el usuario existe
        item = getItemU(pos, *L); //Obtiene el usuario
        deleteListS(&item.songList); //Elimina la lista de canciones
        deleteAtPositionU(pos, L); //Elimina el usuario
        printf("* Delete: user %s category %s totalplaytime %d\n", userName, CategoryToString(item.userCategory), item.totalPlayTime);
    } else {
        printf("+ Error: Delete not possible\n");
    }
}


void Add(tListU *L, tUserName userName, tSongTitle songTitle) {
    /* Objetivo: Añadir una canción a la lista de canciones de un usuario.
     * Entrada:
     *     L: Lista de usuarios.
     *     userName: Nombre del usuario.
     *     songTitle: Título de la canción.
     *     playTime: Tiempo de reproducción de la canción.
     * Salida: La lista de usuarios con la canción añadida a la lista de canciones del usuario.
     * Precondición: La lista de usuarios ha sido creada.
     * Postcondición: La lista de usuarios contiene la canción con el título y tiempo de reproducción indicados en la lista de canciones del usuario.
     */

    tPosU pos;
    tItemU item;
    tItemS song;
    tPosS posS,p;

    pos = findItemU(userName, *L); //Busca el usuario

    if(!isEmptyListU(*L)){ //Si la lista no esta vacia
        if (pos != NULLU) { //Y el usuario existe
            item = getItemU(pos, *L); //Obtiene el usuario
            strcpy(song.songTitle, songTitle); //Copia el titulo de la cancion
            song.playTime = 0;   //Inicializa el tiempo de re
            posS = findItemS(songTitle, item.songList); //Busca la cancion

            if (posS != NULLS) {
                p = firstS(item.songList); //Obtiene la primera cancion
                while (p != NULLS && strcmp(songTitle, getItemS(p, item.songList).songTitle) > 0) { //Recorre la lista de canciones
                    p = nextS(p, item.songList); //Obtiene la siguiente cancion
                }
                insertItemS(song, p, &item.songList); //Inserta la cancion
                updateItemU(item, pos, L); //Actualiza el usuario
                printf("* Add: user %s adds song %s\n", userName, song.songTitle);

            }
            else {
                if(insertItemS(song, lastS(item.songList), &item.songList)){ //Inserta la cancion
                    updateItemU(item, pos, L); //Actualiza el usuario
                    printf("* Add: user %s adds song %s\n", userName, song.songTitle);
                } else {
                    printf("+ Error: Add not possible\n");
                }
            }
        } else {
            printf("+ Error: Add not possible\n");
        }
    }else{
        printf("+ Error: Add not possible\n");
    }
}





void Upgrade(tListU *L, tUserName userName) {
    /* Objetivo: Mejorar la categoría de un usuario.
     * Entrada:
     *     L: Lista de usuarios.
     *     userName: Nombre del usuario.
     * Salida: La lista de usuarios con la categoría del usuario mejorada.
     * Precondición: La lista de usuarios ha sido creada.
     * Postcondición: La lista de usuarios contiene el usuario con la categoría mejorada.
     */
    tPosU pos;
    tItemU item;

    pos = findItemU(userName, *L); //Busca el usuario

    if(isEmptyListU(*L)){ //Si la lista esta vacia no hace nada
        printf("+ Error: Upgrade not possible\n");
        return;
    }

    if(pos!=NULLU && getItemU(pos, *L).userCategory==0) { //Si el usuario existe y es basic
        item = getItemU(pos, *L); //Obtiene el usuario
        item.userCategory++; //Actualiza la categoria
        updateItemU(item, pos, L); //Actualiza el usuario
        printf("* Upgrade: user %s category %s\n", userName, CategoryToString(item.userCategory));
    } else {
        printf("+ Error: Upgrade not possible\n");
    }
}

void Play(tListU *L, tUserName userName, tSongTitle songTitle, tPlayTime playTime) {
    /* Objetivo: Reproducir una canción de un usuario.
     * Entrada:
     *     L: Lista de usuarios.
     *     userName: Nombre del usuario.
     *     songTitle: Título de la canción.
     *     playTime: Tiempo de reproducción de la canción.
     * Salida: La lista de usuarios con la canción reproducida.
     * Precondición: La lista de usuarios ha sido creada.
     * Postcondición: La lista de usuarios contiene la canción reproducida con el tiempo de reproducción indicado.
     */
    tPosU pos;
    tItemU item;
    tItemS song;
    tPosS posS;

    pos = findItemU(userName, *L); //Busca el usuario
    if(isEmptyListU(*L)){ //Si la lista esta vacia no hace nada
        printf("+ Error: Play not possible\n");
        return;
    }

    if (pos != NULLU) { //Si el usuario existe
        item = getItemU(pos, *L); //Obtiene el usuario
        posS = findItemS(songTitle, item.songList); //Busca la cancion

        if(isEmptyListS(item.songList)){ //Si la lista de canciones esta vacia no hace nada
            printf("+ Error: Play not possible\n");
            return;
        }
        if (posS != NULLS) { //Si la cancion existe
            song = getItemS(posS, item.songList); //Obtiene la cancion
            song.playTime += playTime; //Actualiza el tiempo de reproduccion
            updateItemS(song, posS, &item.songList); //Actualiza la cancion
            item.totalPlayTime += playTime; //Actualiza el tiempo total de reproduccion
            updateItemU(item, pos, L); //Actualiza el usuario
            printf("* Play: user %s plays song %s playtime %d totalplaytime %d\n", userName, songTitle, playTime, item.totalPlayTime);
        } else {
            printf("+ Error: Play not possible\n");
        }
    } else {
        printf("+ Error: Play not possible\n");
    }
}

void Stats(tListU *L) {
    /* Objetivo: Mostrar las estadísticas de la lista de usuarios.
     * Entrada:
     *     L: Lista de usuarios.
     * Salida: Por la salida estándar se muestra la información de los usuarios y sus canciones.
     * Precondición: La lista de usuarios ha sido creada.
     */
    tPosU p;
    tItemU d;
    int basic = 0, pro = 0, basicPlays = 0, proPlays = 0; //Inicializa las variables a 0

    if(isEmptyListU(*L)){ //Si la lista esta vacia no hace nada
        printf("+ Error: Stats not possible\n");
        return;
    }

    for (p=firstU(*L); p != NULLU; p = nextU(p, *L)) {  //Recorre la lista de usuarios
        d = getItemU(p, *L); //Obtiene el usuario

        printf("User %s category %s totalplaytime %d\n", d.userName, CategoryToString(d.userCategory), d.totalPlayTime);

        if (d.userCategory == 0) { //Si el usuario es basic
            basic++; //Incrementa el número de basic
            basicPlays += d.totalPlayTime; //Incrementa el tiempo total de reproducción de los basic
        } else {
            pro++; //Incrementa el número de pro
            proPlays += d.totalPlayTime; //Incrementa el tiempo total de reproducción de los pro
        }

        if(isEmptyListS(d.songList)){ //Si la lista de canciones esta vacia no hace nada
            printf("No songs\n");
            printf("\n");
        } else {
            tPosS pS;
            tItemS dS;
            for (pS = firstS(d.songList); pS != NULLS; pS = nextS(pS, d.songList)) { //Recorre la lista de canciones
                dS = getItemS(pS, d.songList); //Obtiene la cancion
                printf("Song %s playtime %d\n", dS.songTitle, dS.playTime);
            }
            printf("\n");
        }
    }

    printf("Category  Users  TimePlay  Average\n");
    if(basic == 0) { //Si no hay basic
        printf("Basic         %d         %d     0.00\n", basic, basicPlays);
    } else {
        printf("Basic         %d         %d     %.2f\n", basic, basicPlays, (float)basicPlays/(float)basic);
    }

    if(pro == 0) { //Si no hay pro
        printf("Pro           %d         %d     0.00\n", pro, proPlays);
    } else {
        printf("Pro           %d         %d     %.2f\n", pro, proPlays, (float)proPlays/(float)pro);
    }
}



void Remove(tListU *L, tPlayTime maxTime) {
    /* Objetivo: Eliminar los usuarios que no han superado un tiempo de reproducción.
     * Entrada:
     *     L: Lista de usuarios.
     *     maxTime: Tiempo de reproducción.
     * Salida: La lista de usuarios sin los usuarios que no han superado el tiempo de reproducción.
     * Precondición: La lista de usuarios ha sido creada.
     * Postcondición: La lista de usuarios no contiene los usuarios que no han superado el tiempo de reproducción.
     */
    tPosU p = firstU(*L),aux;
    tItemU item;

    bool removed=false; //Inicializa la variable de si está borrado a false
    if (!isEmptyListU(*L)) { //Si la lista no esta vacia
        while (p != NULLU) { //Recorre la lista de usuarios
            item = getItemU(p, *L); //Obtiene el usuario
            if (item.userCategory == 0 && item.totalPlayTime > maxTime) { //Si el usuario es basic y ha superado el tiempo de reproduccion
                printf("Removing user %s totalplaytime %d\n", item.userName, item.totalPlayTime);
                removed=true; //Actualiza la variable conforme si está borrado
                aux=p;  //Guarda la posicion del usuario
                if(isEmptyListS(item.songList)){ //Si la lista de canciones esta vacia no hace nada
                    deleteAtPositionU(aux, L); //Elimina el usuario
                    p= firstU(*L); //Actualiza la posicion
                }
                else{
                    deleteListS(&item.songList); //Elimina la lista de canciones
                    deleteAtPositionU(aux,L); //Elimina el usuario
                    p= firstU(*L); //Actualiza la posicion
                }


            } else {
                p = nextU(p, *L); //Obtiene el siguiente usuario
            }
        }
        if(!removed){
            printf("+ Error: Remove not possible\n");
        }
    } else {
        printf("+ Error: Remove not possible\n");
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
            Add(L, param1, param2);
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
            printf("%s %c: maxtime %s\n", commandNumber, command, param1);
            Remove(L,atoi(param1));
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tListU L;

    createEmptyListU(&L);

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

    char *file_name = "new.txt";

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