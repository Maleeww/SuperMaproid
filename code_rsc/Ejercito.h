#ifndef __Ejercito_H__
#define __Ejercito_H__
#include "Pantalla.h"
#include "Disparo.h"
#include "Enemigo.h"

/**
   \file Ejercito.h
   \brief Implementa las funciones del TDA Ejercito
 */

/**
\brief TDA Ejercito
 */
typedef struct EjercitoRep * Ejercito;

/**
\brief Crea un ejército en memoria como una lista de datos enlazada de enemigos vacía
 */
Ejercito EjercitoCrea();

/**
\brief Libera de memoria el Ejército y los enemigos de dicho ejército
\param ej Ejército a liberar de memoria
 */
void EjercitoLibera(Ejercito ej);

/**
\brief Inserta un enémigo en el ejército, creando una nueva celda con dicho enemigo e insertándola al principio
\param ej Ejército en el que insertar
\param i Imagen del enemigo a insertar
\param i1 Frame de destrucción 1 del enemigo
\param i2 Frame de destrucción 2 del enemigo
\param i3 Frame de destrucción 3 del enemigo
\param i4 Frame de destrucción 4 del enemigo
\param i5 Frame de destrucción 5 del enemigo
\param i6 Frame de destrucción 6 del enemigo
\param i7 Frame de destrucción 7 del enemigo
\param i8 Frame de destrucción 8 del enemigo
\param i9 Frame de destrucción 9 del enemigo
\param i10 Frame de destrucción 10 del enemigo
\param i11 Frame de destrucción 11 del enemigo
\param x Posición x del enemigo a insertar
\param y Posición y del enemigo
\param w Anchura del enemigo
\param h Altura del enemigo
\param vx Velocidad en el eje x del enemigo
\param vy Velocidad en el eje y del enemigo
 */
void EjercitoInserta(Ejercito ej, Imagen i,Imagen i1,Imagen i2,Imagen i3,Imagen i4,Imagen i5,Imagen i6,Imagen i7,Imagen i8,Imagen i9,Imagen i10,Imagen i11, int x, int y , int w, int h, int vx, int vy);

/**
\brief Calcula si alguno de los enemigos en el ejército colisiona con el objeto pasado por parámetros
\param ej Ejército con el que puede colisionar el objeto
\param x Posición x del objeto
\param y Posición y del objeto
\param w Anchura del objeto
\param h Altura del objeto
\return Devuelve el enemigo del ejército con el que ha colisionado
 */
int EjercitoColision(Ejercito ej, int x, int y, int w, int h);

/**
\brief Recorre el ejército dibujando cada uno de los enemigos existentes
\param ej Ejército a dibujar
 */
void EjercitoDibuja(Ejercito ej);

/**
\brief Mueve cada enemigo del ejército según la velocidad asociada de cada uno
\param ej Ejército a mover
 */
void EjercitoMueve(Ejercito ej);

/** Calcula si alguno de los enemigos a colisionado con el rayo recibido
\param ej Ejército que puede colisionar con el rayo
\param r Rayo con el que puede colisionar
\return Devuelve 1 en el caso de que colisione con el rayo
 */
int EjercitoColisionRayo(Ejercito ej, Rayo r);


/**
\brief Dibuja la imagen pasada tantas veces como indique el entero recibido hacia la izquierda
\param i Entero que indica el número de imágenes a dibujar
\param im Imagen a dibujar
 */
void  EjercitoDibujaVida(int i,Imagen im);


#endif
