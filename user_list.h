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
/*
 *Objetivo: Crea una lista de usuarios vacía y la inicializa.
 * Salida: Una lista vacía.
 * Postcondición: La lista sin datos.
 */
bool isEmptyListU(tListU L);
/*
 *Objetivo: Determina si la lista de usuarios está vacía.
 * Salida: Verdadero si la lista está vacía, falso en caso contrario.
 * Precodición: La lista ha sido creada.
 */
tPosU firstU(tListU L);
/*
 *Objetivo: Devuelve la posición del primer elemento de la lista de usuarios.
 * Salida: Posición del primer elemento de la lista.
 * Precodición: La lista no está vacía.
 */
tPosU lastU(tListU L);
/*
 *Objetivo: Devuelve la posición del último elemento de la lista de usuarios.
 * Salida: Posición del último elemento de la lista.
 * Precodición: La lista no está vacía.
 */
tPosU nextU(tPosU p, tListU L);
/*
 *Objetivo: Devuelve la posición del elemento siguiente al indicado.
 * Entrada:
 * p: Posición de un elemento de la lista.
 * L: Lista de la que se toma el elemento.
 * Salida: Posición del elemento siguiente al indicado.
 * Precodición: La lista de usuarios no está vacía y p no es la última posición.
 */
tPosU previousU(tPosU p, tListU L);
/*
 *Objetivo: Devuelve la posición del elemento anterior al indicado.
 * Salida: Posición del elemento anterior al indicado.
 * Precodición: La lista de usuarios no está vacía y p no es la primera posición.
 */
bool insertItemU(tItemU d, tListU *L);
/*
 *Objetivo: Inserta un elemento en la lista de usuarios.
 *Salida: Verdadero si el elemento fue insertado, falso en caso contrario.
 *Precodición: La lista no está llena.
 */
void deleteAtPositionU(tPosU p,tListU *L);
/*
 *Objetivo: Elimina un elemento de la lista de usuarios.
 *Salida: La lista sin el elemento en la posición p.
 *Precodición: La lista de usuarios no está vacía y p es una posición válida.
 */
tItemU getItemU(tPosU p,tListU L);
/*
 * Objetivo: Devuelve el elemento de la lista de usuarios en la posición p.
 * Salida: Elemento de la lista en la posición p.
 * Precodición: La lista de usuarios no está vacía y p es una posición válida.
 */
void updateItemU(tItemU d,tPosU p,tListU *L);
/*
 * Objetivo: Actualiza el elemento de la lista de canciones en la posición p.
 * Salida: La lista con el elemento actualizado.
 * Precodición: La lista de canciones no está vacía y p es una posición válida.
 */
tPosU findItemU(tUserName d,tListU L);
/*
 * Objetivo: Busca un elemento en la lista de usuarios.
 * Salida: Posición del elemento en la lista o NULLS si no se encuentra.
 * Precodición: La lista de usuarios ha sido creada.
 */



#endif
