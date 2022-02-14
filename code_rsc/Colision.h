#ifndef __colision_H__
#define __colision_H__

/**
   \file Colision.h
   \brief Implementa la función que calcula la distancia entre dos objetos y decide si colisionan o no
 */

/**
\brief Calcula la distancia entre dos objetos según sus coordenadas y tamaños
\param x1 Coordenada x del primer objeto
\param y1 Coordenada y del primer objeto
\param w1 Ancho del primer objeto
\param h1 Alto del primer objeto
\param x2 Coordenada x del segundo objeto
\param y2 Coordenada y del segundoobjeto
\param w2 Ancho del segundo objeto
\param h2 Alto del segundo objeto
 */
int colision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif
