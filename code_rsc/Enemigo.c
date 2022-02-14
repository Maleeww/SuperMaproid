#include "Enemigo.h"
#include "Pantalla.h"
#include <stdlib.h>

struct EnemigoRep
{
    Imagen i,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
    int x,y,w,h,vx,vy,frame;
};
int techo = -10;
Enemigo EnemigoCrea(Imagen i, Imagen i1, Imagen i2, Imagen i3, Imagen i4, Imagen i5, Imagen i6, Imagen i7, Imagen i8, Imagen i9, Imagen i10, Imagen i11, int x, int y, int w, int h, int vx, int vy)
{
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e->i = i;
    e->i1 = i1;
    e->i2 = i2;
    e->i3 = i3;
    e->i4 = i4;
    e->i5 = i5;
    e->i6 = i6;
    e->i7 = i7;
    e->i8 = i8;
    e->i9 = i9;
    e->i10 = i10;
    e->i11 = i11;
    e->x = x;
    e->y = y;
    e->w = w;
    e->h = h;
    e->vx = vx;
    e->vy = vy;
    e->frame = 0; //indica si ha colisionado con algun disparo, si no, es que ha colisionado con el personaje

    return e;
}

void EnemigoLibera(Enemigo e)
{
    free(e);
}


void EnemigoMueve(Enemigo e)
{
    e->x = e->x+e->vx;
    e->y = e->y+e->vy;
    if (e->x>Pantalla_Anchura()-e->w)
        e->vx=e->vx*(-1);
    if (e->x<0)
        e->vx=e->vx*(-1);
    if (e->y>Pantalla_Altura()-e->h)
        e->vy=e->vy*(-1);
    if (e->y<0)
        e->vy=e->vy*(-1);
}
void EnemigoDibuja(Enemigo e)
{
    switch((e->frame)/2)
    {
    case(0):
        Pantalla_DibujaImagen(e->i,e->x,e->y,e->w,e->h);
        break;
    case(1):
    {
        Pantalla_DibujaImagen(e->i1,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(2):
    {
        Pantalla_DibujaImagen(e->i2,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(3):
    {
        Pantalla_DibujaImagen(e->i3,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(4):
    {
        Pantalla_DibujaImagen(e->i4,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(5):
    {
        Pantalla_DibujaImagen(e->i5,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(6):
    {
        Pantalla_DibujaImagen(e->i6,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(7):
    {
        Pantalla_DibujaImagen(e->i7,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(8):
    {
        Pantalla_DibujaImagen(e->i8,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(9):
    {
        Pantalla_DibujaImagen(e->i9,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(10):
    {
        Pantalla_DibujaImagen(e->i10,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    case(11):
    {
        Pantalla_DibujaImagen(e->i11,e->x,e->y,e->w,e->h);
        e->frame=e->frame+1;
        break;
    };
    }


}

void EnemigoAvanzaFrame(Enemigo e)
{
    e->frame=5;
}
int EnemigoCompruebaFrame(Enemigo e)
{
    return e->frame;
}

int  EnemigoGetX(Enemigo e)
{
    return e->x;
}
int  EnemigoGetY(Enemigo e)
{
    return e->y;
}

int  EnemigoGetH(Enemigo e)
{
    return e->h;
}
int  EnemigoGetW(Enemigo e)
{
    return e->w;
}





