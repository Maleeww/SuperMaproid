#ifndef __Boton_H__
#define __Boton_H__
#include "Pantalla.h"
/**
   \file Boton.h
   \brief Implementa las funciones del TDA Boton
 */
/**
    \brief TDA Boton
 */
typedef struct BotonRep * Boton;

/**
\brief Crea un boton con dos posibilidades, pulsado o no pulsado
\param i Imagen original (sin el ratón encima)
\param i2 Imagen secundaria (con el ratón encima)
\param x Posición x del botón
\param y Posición y del botón
\param w Anchura del botón
\param h Altura del botón
\return La variable boton creada
 */
Boton BotonCrea(Imagen i,Imagen i2,int x, int y, int w, int h);

/**
\brief Elige entre las dos imágenes del botón a dibujar según la posición del ratón y devuelve un
\param b Boton a dibujar
\param mousex Coordenada x del ratón
\param mousey Coordenada y del ratón
\return Entero que indica si está pulsado o no el botón
 */
int BotonDibuja(Boton b,int mousex, int mousey);

/**
\brief Libera el botón creado
\param b Boton a liberar
*/
void BotonLibera(Boton b);


#endif
