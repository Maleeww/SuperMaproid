#ifndef __Disparo_H__
#define __Disparo_H__
#include "Personaje.h"
#include "Pantalla.h"

/**
   \file Disparo.h
   \brief Implementa las funciones del TDA Disparo y del TDA Rayo usando funciones del Personaje
 */

/**
\brief TDA Disparo
 */
typedef struct DisparoRep * Disparo;

/**
 TDA Rayo
 */
typedef struct RayoRep * Rayo;

/**
\brief Crea un tipo disparo con un movimiento predeterminado
\param i Imagne del disparo
\param x Posición inicial x del disparo
\param y Posición inicial y del disparo
\param w Ancho del disparo
\param h Alto del disparo
\param vx Movimiento en el eje x (velocidad lateral)
\param vy Movimiento en el eje y (velocidad vertical)
\return Variable disparo creada
 */
Disparo DisparoCrea(Imagen i,int x, int y, int w, int h, int vx, int vy);

/**
\brief Libera la memoria reservada de la variable disparo que recibe
\param d Disparo a liberar de memoria
*/
void DisparoLibera(Disparo d);

/**
\brief Modifica directamente los valores x e y del tipo Disparo pedido
\param d Disparo a mover
 */
void DisparoMueve(Disparo d);

/**
\brief Llamada a otra función que dibuja el disparo según sus parametros internos
\param d Disparo a dibujar en la pantalla
*/
void DisparoDibuja(Disparo d);

/**
\brief Devuelve el valor de x interno del disparo
\param d Disparo al que pedimos su x (d->x)
\return Posición x del disparo d
*/
int  DisparoGetX(Disparo d);

/**
\brief Devuelve el valor de y interno del disparo
\param d Disparo al que pedimos su y (d->y)
\return Posición y del disparo d
*/
int  DisparoGetY(Disparo d);

/**
\brief Devuelve el valor de h interno del disparo
\param d Disparo al que pedimos su h (d->h)
\return Altura h del disparo d
*/
int  DisparoGetH(Disparo d);

/**
\brief Devuelve el valor de w interno del disparo
\param d Disparo al que pedimos su w (d->w)
\return Anchura w del disparo d
*/
int  DisparoGetW(Disparo d);

/**
\brief Crea un tipo rayo con dos posiciones, una para cada uno de los dos rayos que lo forman
\param i Imagen del rayo
\param p Personaje al que se asocia el rayo y al que tiene que seguir
\param x Posición x del primer rayo
\param x2 Posición x del segundo rayo
\param y Posición y de ambos rayos
\param w Ancho de ambos rayos
\param h Alto de ambos rayos
\return Variable disparo creada
 */
Rayo RayoCrea(Imagen i, Personaje p,int x, int x2, int y, int w, int h);

/**
\brief Devuelve el valor de x interno del primer rayo
\param r Rayo al que pedimos su x (r->x)
\return Posición x del primer rayo de r
*/
int  RayoGetX(Rayo r);

/**
\brief Devuelve el valor de x interno del segundo rayo
\param r Rayo al que pedimos su x2 (r->x2)
\return Posición x del segundo rayo de r
*/
int  RayoGetX2(Rayo r);

/**
\brief Devuelve el valor de y interno del rayo
\param r Rayo al que pedimos su y (r->y)
\return Posición y del rayo r
*/
int  RayoGetY(Rayo r);

/**
\brief Devuelve el valor de h interno del rayo
\param r Rayo al que pedimos su h (r->h)
\return Altura h del rayo r
*/
int  RayoGetH(Rayo r);

/**
\brief Devuelve el valor de w interno del rayo
\param r Rayo al que pedimos su w (r->w)
\return Anchura w del rayo r
*/
int  RayoGetW(Rayo r);

/**
\brief Dibuja el rayo en relación con el personaje al que se le asocia
\param r Rayo a dibujar
 */
void RayoDibuja(Rayo r);

/**
\brief Calcula si un objeto choca con alguno de los rayos pasando los parámetros de ese objeto, y si lo hace, devuelve un 1
\param r Rayos con los que puede chocar el objeto
\param x Posición x de dicho objeto
\param y Posición y del objeto
\param w Anchura del objeto
\param h Altura del objeto
\return Devuelve 1 si el objeto sí choca con los rayos
 */
int RayoColision(Rayo r, int x, int y, int w, int h);

/**
\brief Libera el rayo creado
\param r Rayo a liberal
*/
void RayoLibera(Rayo r);


#endif
