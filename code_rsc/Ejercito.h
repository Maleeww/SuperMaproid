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
\brief Crea un ej�rcito en memoria como una lista de datos enlazada de enemigos vac�a
 */
Ejercito EjercitoCrea();

/**
\brief Libera de memoria el Ej�rcito y los enemigos de dicho ej�rcito
\param ej Ej�rcito a liberar de memoria
 */
void EjercitoLibera(Ejercito ej);

/**
\brief Inserta un en�migo en el ej�rcito, creando una nueva celda con dicho enemigo e insert�ndola al principio
\param ej Ej�rcito en el que insertar
\param i Imagen del enemigo a insertar
\param i1 Frame de destrucci�n 1 del enemigo
\param i2 Frame de destrucci�n 2 del enemigo
\param i3 Frame de destrucci�n 3 del enemigo
\param i4 Frame de destrucci�n 4 del enemigo
\param i5 Frame de destrucci�n 5 del enemigo
\param i6 Frame de destrucci�n 6 del enemigo
\param i7 Frame de destrucci�n 7 del enemigo
\param i8 Frame de destrucci�n 8 del enemigo
\param i9 Frame de destrucci�n 9 del enemigo
\param i10 Frame de destrucci�n 10 del enemigo
\param i11 Frame de destrucci�n 11 del enemigo
\param x Posici�n x del enemigo a insertar
\param y Posici�n y del enemigo
\param w Anchura del enemigo
\param h Altura del enemigo
\param vx Velocidad en el eje x del enemigo
\param vy Velocidad en el eje y del enemigo
 */
void EjercitoInserta(Ejercito ej, Imagen i,Imagen i1,Imagen i2,Imagen i3,Imagen i4,Imagen i5,Imagen i6,Imagen i7,Imagen i8,Imagen i9,Imagen i10,Imagen i11, int x, int y , int w, int h, int vx, int vy);

/**
\brief Calcula si alguno de los enemigos en el ej�rcito colisiona con el objeto pasado por par�metros
\param ej Ej�rcito con el que puede colisionar el objeto
\param x Posici�n x del objeto
\param y Posici�n y del objeto
\param w Anchura del objeto
\param h Altura del objeto
\return Devuelve el enemigo del ej�rcito con el que ha colisionado
 */
int EjercitoColision(Ejercito ej, int x, int y, int w, int h);

/**
\brief Recorre el ej�rcito dibujando cada uno de los enemigos existentes
\param ej Ej�rcito a dibujar
 */
void EjercitoDibuja(Ejercito ej);

/**
\brief Mueve cada enemigo del ej�rcito seg�n la velocidad asociada de cada uno
\param ej Ej�rcito a mover
 */
void EjercitoMueve(Ejercito ej);

/** Calcula si alguno de los enemigos a colisionado con el rayo recibido
\param ej Ej�rcito que puede colisionar con el rayo
\param r Rayo con el que puede colisionar
\return Devuelve 1 en el caso de que colisione con el rayo
 */
int EjercitoColisionRayo(Ejercito ej, Rayo r);


/**
\brief Dibuja la imagen pasada tantas veces como indique el entero recibido hacia la izquierda
\param i Entero que indica el n�mero de im�genes a dibujar
\param im Imagen a dibujar
 */
void  EjercitoDibujaVida(int i,Imagen im);


#endif
