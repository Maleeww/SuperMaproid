#ifndef __Enemigo_H__
#define __Enemigo_H__
#include "Pantalla.h"

/**
   \file Enemigo.h
   \brief Implementa las funciones del TDA Enemigo
 */

/**
\brief TDA Enemigo
 */
typedef struct EnemigoRep * Enemigo;

/**
\brief Crea un enemigo con 1 imagen y otras 4 para su destrucción, con velocidad constante
\param i Imagen original
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
\param x Posición x original del enemigo
\param y Posición y original del enemigo
\param w Ancho del enemigo
\param h Alto del enemigo
\param vx Velocidad en el eje x
\param vy Velocidad en el eje y
\return Variable enemigo creada con los anteriores parametros
 */
Enemigo EnemigoCrea(Imagen i, Imagen i1, Imagen i2, Imagen i3, Imagen i4,Imagen i5, Imagen i6, Imagen i7, Imagen i8, Imagen i9, Imagen i10, Imagen i11,int x, int y, int w, int h, int vx, int vy);

/**
\brief Libera de memoria el espacio usado por el enemigo
\param e Enemigo a liberar de memoria
 */
void EnemigoLibera(Enemigo e);


/**
\brief Mueve el enemigo en la dirección que indican sus parámetros internos
\param e Enemigo a mover
 */
void EnemigoMueve(Enemigo e);

/**
\brief Dibuja el enemigo en pantalla
\param e Enemigo a dibujar en pantalla
 */
void EnemigoDibuja(Enemigo e);

/**
\brief Devuelve el parámetro interno 'x', la posición en el eje x del Enemigo
\param e Enemigo al que se le pide la posición x
\return Entero que indica la posición x del enemigo
 */
int EnemigoGetX(Enemigo e);

/**
\brief Devuelve el parámetro interno 'y', la posición en el eje y del Enemigo
\param e Enemigo al que se le pide la posición y
\return Entero que indica la posición y del enemigo
 */
int EnemigoGetY(Enemigo e);

/**
\brief Devuelve el parámetro interno 'h', alto del Enemigo
\param e Enemigo al que se le pide el alto h
\return Entero que indica el alto h del enemigo
 */
int EnemigoGetH(Enemigo e);

/**
\brief Devuelve el parámetro interno 'w', ancho del Enemigo
\param e Enemigo al que se le pide el ancho w
\return Entero que indica el ancho w del enemigo
 */
int EnemigoGetW(Enemigo e);

/**
\brief Suma 1 al frame en el que se encuentra en el enemigo
\param e Enemigo al que avanzar el frame
 */
void EnemigoAvanzaFrame(Enemigo e);

/**
\brief Devuelve el frame en el que se encuentra el enemigo
\param e Enemigo al que se le pide el frame
\return Entero que indica el frame del enemigo en este momento
 */
int EnemigoCompruebaFrame(Enemigo e);








#endif
