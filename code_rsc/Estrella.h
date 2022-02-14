#ifndef __Estrella_H__
#define __Estrella_H__
#include "Pantalla.h"

/**
   \file Estrella.h
   \brief Implementa las funciones del TDA Estrella
 */

/**
\brief TDA Estrella
 */
typedef struct EstrellaRep * Estrella;

/**
\brief Crea la variable Estrella
\param i Imagen i de la estrella
\param x Posición x de la estrella
\param y Posición y de la estrella
\param w Ancho de la estrella
\param h Alto de la estrella
\return Variable estrella creada
 */
Estrella EstrellaCrea(Imagen i,int x, int y, int w, int h);

/**
\brief Libera de memoria el espacio ocupado por la variable estrella
\param e Estrella a liberar de memoria
 */
void EstrellaLibera(Estrella e);

/**
\brief Dibuja en pantalla la variable estrella
\param e Estrella a dibujar
 */
void EstrellaDibuja(Estrella e);

/**
\brief Devuelve la posición en x de Estrella
\param e Estrella a la que se le pide x
\return Posición x de la estrella
 */
int  EstrellaGetX(Estrella e);

/**
\brief Devuelve la posición en y de Estrella
\param e Estrella a la que se le pide y
\return Posición y de la estrella
 */
int  EstrellaGetY(Estrella e);

/**
\brief Devuelve el alto h de Estrella
\param e Estrella a la que se le pide h
\return Alto h de la estrella
 */
int  EstrellaGetH(Estrella e);

/**
\brief Devuelve el ancho w de Estrella
\param e Estrella a la que se le pide w
\return Ancho w de la estrella
 */
int  EstrellaGetW(Estrella e);

#endif
