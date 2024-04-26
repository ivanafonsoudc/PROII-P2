/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 2
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 12/ 04 / 24
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
/*
 *Objetivo: Crea una lista de canciones vacía y la inicializa.
 * Salida: Una lista vacía.
 * Postcondición: La lista sin datos.
 */
bool isEmptyListS(tListS L);
/*
 *Objetivo: Determina si la lista de canciones está vacía.
 * Salida: Verdadero si la lista está vacía, falso en caso contrario.
 * Precodición: La lista ha sido creada.
 */
tPosS firstS(tListS L);
/*
 *Objetivo: Devuelve la posición del primer elemento de la lista de canciones.
 * Salida: Posición del primer elemento de la lista.
 * Precodición: La lista no está vacía.
 */
tPosS lastS(tListS L);
/*
 *Objetivo: Devuelve la posición del último elemento de la lista de canciones.
 * Salida: Posición del último elemento de la lista.
 * Precodición: La lista no está vacía.
 */
tPosS nextS(tPosS p, tListS L);
/*
 *Objetivo: Devuelve la posición del elemento siguiente al indicado.
 * Entrada:
 * p: Posición de un elemento de la lista.
 * L: Lista de la que se toma el elemento.
 * Salida: Posición del elemento siguiente al indicado.
 * Precodición: La lista de canciones no está vacía y p no es la última posición.
 */
tPosS previousS(tPosS p, tListS L);
/*
 *Objetivo: Devuelve la posición del elemento anterior al indicado.
 * Salida: Posición del elemento anterior al indicado.
 * Precodición: La lista de canciones no está vacía y p no es la primera posición.
 */
bool insertItemS(tItemS d,tPosS p, tListS *L);
/*
 *Objetivo: Inserta un elemento en la lista de canciones.
 *Salida: Verdadero si el elemento fue insertado, falso en caso contrario.
 *Precodición: La lista no está llena.
 */
void deleteAtPositionS(tPosS p,tListS *L);
/*
 *Objetivo: Elimina un elemento de la lista.
 *Salida: La lista sin el elemento en la posición p.
 *Precodición: La lista de canciones no está vacía y p es una posición válida.
 */
tItemS getItemS(tPosS p,tListS L);
/*
 * Objetivo: Devuelve el elemento de la lista de canciones en la posición p.
 * Salida: Elemento de la lista en la posición p.
 * Precodición: La lista de canciones no está vacía y p es una posición válida.
 */
void updateItemS(tItemS d,tPosS p,tListS *L);
/*
 * Objetivo: Actualiza el elemento de la lista de canciones en la posición p.
 * Salida: La lista con el elemento actualizado.
 * Precodición: La lista de canciones no está vacía y p es una posición válida.
 */
tPosS findItemS(tUserName d,tListS L);
/*
 * Objetivo: Busca un elemento en la lista de canciones.
 * Salida: Posición del elemento en la lista o NULLS si no se encuentra.
 * Precodición: La lista de canciones ha sido creada.
 */






#endif
