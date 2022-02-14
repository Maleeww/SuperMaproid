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
\param i Imagen original (sin el rat�n encima)
\param i2 Imagen secundaria (con el rat�n encima)
\param x Posici�n x del bot�n
\param y Posici�n y del bot�n
\param w Anchura del bot�n
\param h Altura del bot�n
\return La variable boton creada
 */
Boton BotonCrea(Imagen i,Imagen i2,int x, int y, int w, int h);

/**
\brief Elige entre las dos im�genes del bot�n a dibujar seg�n la posici�n del rat�n y devuelve un
\param b Boton a dibujar
\param mousex Coordenada x del rat�n
\param mousey Coordenada y del rat�n
\return Entero que indica si est� pulsado o no el bot�n
 */
int BotonDibuja(Boton b,int mousex, int mousey);

/**
\brief Libera el bot�n creado
\param b Boton a liberar
*/
void BotonLibera(Boton b);


#endif
