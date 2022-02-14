#ifndef __Personaje_H__
#define __Personaje_H__
#include "Pantalla.h"

/**
   \file Personaje.h
   \brief Implementación del TDA Personaje.
*/

/**
    \brief TDA Personaje
 */
typedef struct PersonajeRep * Personaje;

/**
\brief Crea una variable de tipo Personaje con posición, tamaño e imagen relacionada
\param i Imagen asociada
\param movi Imagen en movimiento hacia arriba o hacia abajo
\param izqi Imagen en movimiento hacia la izquierda
\param deri Imagen en movimiento hacia la derecha
\param x Coordenada x en la que se encuentra
\param y Coordenada y en la que se encuentra
\param w Anchura del personaje
\param h Altura del personaje
\return La variable de tipo Personaje
*/
Personaje PersonajeCrea(Imagen i, Imagen movi, Imagen izqi, Imagen deri, int x, int y, int w, int h);

/**
\brief Libera la memoria reservada del personaje que se pide
\param p Personaje a liberar de memoria
*/
void PersonajeLibera(Personaje p);

/**
\brief Llama a otra función llamada PersonajeMueve con unos parametros que se eligen según el input del teclado
\param p El personaje al que hay que modificar sus coordenadas
\param sprint Valor que indica si hay que mover la coordenada 10 píxeles o 20
*/
void PersonajeMov(Personaje p, int sprint);

/**
\brief Modifica directamente los valores x e y del tipo Personaje pedido
\param p Personaje a mover
\param mx Número de píxeles en la coordenada x a mover
\param my Número de píxeles en la coordenada y a mover
*/
void PersonajeMueve(Personaje p, int mx, int my);

/**
\brief Llamada a otra que dibuja el personaje según sus parámaetros
\param p Personaje a dibujar en la pantalla
\param pmov Estado de movimiento en el que se encuentra
*/
void PersonajeDibuja(Personaje p, int pmov);

/**
\brief Devuelve el valor de x interno del personaje
\param p Personaje al que pedimos su x (p->x)
\return Posición x del personaje p
*/
int  PersonajeGetX(Personaje p);

/**
\brief Devuelve el valor de y interno del personaje
\param p Personaje al que pedimos su y (p->y)
\return Posición y del personaje p
*/
int  PersonajeGetY(Personaje p);

/**
\brief Devuelve el valor de h interno del personaje
\param p Personaje al que pedimos su h (p->h)
\return Altura h del personaje p
*/
int  PersonajeGetH(Personaje p);

/**
\brief Devuelve el valor de w interno del personaje
\param p Personaje al que pedimos su w (p->w)
\return Anchura w del personaje p
*/
int  PersonajeGetW(Personaje p);

/**
\brief Dibuja en pantalla la imagen pasada tantas veces como se indique en el parámetro i pasado
\param i Valor que indica el número de veces a dibujar
\param im Tipo imagen a dibujar
*/
void  PersonajeDibujaVida(int i,Imagen im);

/**
\brief Lee el entero recibido y lo dibuja con imágenes en la posición recibida
\param i0 Imagen del número 0
\param i1 Imagen del número 1
\param i2 Imagen del número 2
\param i3 Imagen del número 3
\param i4 Imagen del número 4
\param i5 Imagen del número 5
\param i6 Imagen del número 6
\param i7 Imagen del número 7
\param i8 Imagen del número 8
\param i9 Imagen del número 9
\param n Número entero a dibujar
\param x Posición x donde dibujarlo
\param y Posición y donde dibujarlo
\param w Anchura de cada número
\param h Altura de cada número
*/
void NumAText(Imagen i0,Imagen i1,Imagen i2,Imagen i3,Imagen i4,Imagen i5,Imagen i6,Imagen i7,Imagen i8,Imagen i9,int n,int x,int y,int w, int h);


#endif
