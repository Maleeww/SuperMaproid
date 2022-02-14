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
\brief Crea un enemigo con 1 imagen y otras 4 para su destrucci�n, con velocidad constante
\param i Imagen original
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
\param x Posici�n x original del enemigo
\param y Posici�n y original del enemigo
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
\brief Mueve el enemigo en la direcci�n que indican sus par�metros internos
\param e Enemigo a mover
 */
void EnemigoMueve(Enemigo e);

/**
\brief Dibuja el enemigo en pantalla
\param e Enemigo a dibujar en pantalla
 */
void EnemigoDibuja(Enemigo e);

/**
\brief Devuelve el par�metro interno 'x', la posici�n en el eje x del Enemigo
\param e Enemigo al que se le pide la posici�n x
\return Entero que indica la posici�n x del enemigo
 */
int EnemigoGetX(Enemigo e);

/**
\brief Devuelve el par�metro interno 'y', la posici�n en el eje y del Enemigo
\param e Enemigo al que se le pide la posici�n y
\return Entero que indica la posici�n y del enemigo
 */
int EnemigoGetY(Enemigo e);

/**
\brief Devuelve el par�metro interno 'h', alto del Enemigo
\param e Enemigo al que se le pide el alto h
\return Entero que indica el alto h del enemigo
 */
int EnemigoGetH(Enemigo e);

/**
\brief Devuelve el par�metro interno 'w', ancho del Enemigo
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
