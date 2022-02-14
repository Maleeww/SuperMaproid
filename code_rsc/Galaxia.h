
#ifndef __Galaxia_H__
#define __Estrella_H__
#include "Pantalla.h"

/**
   \file Galaxia.h
   \brief Implementa las funciones del TDA Galaxia
 */

/**
\brief TDA Galaxia
 */
typedef struct GalaxiaRep * Galaxia;

/** Crea la variable galaxia
\param nmax Número máximo de elementos en la galaxia
\return Devuelve la variable galaxia creada
 */
Galaxia GalaxiaCrea(int nmax);

/** Inserta una estrella en la galaxia
\param g Galaxia en la que insertar la estrella
\param i Imagen de la estrella a crear en la galaxia
\param x x de estrella
\param y y de estrella
\param w ancho de estrella
\param h alto de estrella
 */
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h);

/** Libera la galaxia
\param g Galaxia a liberar
 */
void GalaxiaLibera(Galaxia g);

/** Dibuja la galaxia en pantalla
\param g Galaxia a dibujar
 */
void GalaxiaDibuja(Galaxia g);

/** Comprueba si alguna de las estrellas ha colisionado con el objeto
\param g Galaxia a comprobar
\param x x del objeto
\param y y del objeto
\param w ancho del objeto
\param h alto del objeto
 */
int GalaxiaColision(Galaxia g, int x, int y, int w, int h);

#endif
