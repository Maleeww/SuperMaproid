#include "Boton.h"
#include <stdlib.h>

struct BotonRep
{
    Imagen i, i2;
    int x,y,w,h;
};

Boton BotonCrea(Imagen i,Imagen i2,int x, int y, int w, int h)
{
    Boton b = malloc(sizeof(struct BotonRep));
    b->i=i;
    b->i2=i2;
    b->x=x;
    b->y=y;
    b->w=w;
    b->h=h;
    return b;
}




int BotonDibuja(Boton b,int mousex, int mousey)
{
    int resultado = 0;
    if ((mousex>b->x)&&(mousex<(b->x+b->w))&&(mousey>b->y)&&(mousey<(b->y+b->h)))
    {
        Pantalla_DibujaImagen(b->i2,b->x,b->y,b->w,b->h);
        if (Pantalla_RatonBotonPulsado(SDL_MOUSEBUTTONDOWN))
            resultado = 1;
    }
    else
        Pantalla_DibujaImagen(b->i,b->x,b->y,b->w,b->h);
    return resultado;
}

void BotonLibera(Boton b)
{
    free(b);
}
