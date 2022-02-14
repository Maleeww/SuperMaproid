#include "Disparo.h"
#include "Personaje.h"
#include <stdlib.h>

struct DisparoRep
{
    Imagen i;
    int x,y,w,h,vx,vy;
};
//habilidad especial T
struct RayoRep
{
    Imagen i;
    Personaje p;
    int x,x2,y,w,h;
};


Disparo DisparoCrea(Imagen i,int x, int y, int w, int h, int vx, int vy)
{
    Disparo d = malloc(sizeof(struct DisparoRep));
    d->i = i;
    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
    d->vx = vx;
    d->vy = vy;

    return d;
}
void DisparoLibera(Disparo d)
{
    free(d);
}
void DisparoMueve(Disparo d)
{
    d->x = d->x+d->vx;
    d->y = d->y+d->vy;
    if (d->x>Pantalla_Anchura()-d->w) d->vx=d->vx*(-1);
    if (d->x<0) d->vx=d->vx*(-1);
    if (d->y>Pantalla_Altura()-d->h) d->vy=d->vy*(-1);
    if (d->y<0) d->vy=d->vy*(-1);
}
void DisparoDibuja(Disparo d)
{
    Pantalla_DibujaImagen(d->i,d->x,d->y,d->h,d->w);
};
int  DisparoGetX(Disparo d)
{
    return d->x;
}
int  DisparoGetY(Disparo d)
{
    return d->y;
}
int  DisparoGetH(Disparo d)
{
    return d->h;
}
int  DisparoGetW(Disparo d)
{
    return d->w;
}

Rayo RayoCrea(Imagen i,Personaje p, int x, int x2, int y, int w, int h)
{
    Rayo r = malloc(sizeof(struct RayoRep));
    r->i = i;
    r->x = x;
    r->x2 = x2;
    r->y = y;
    r->w = w;
    r->h = h;
    r->p = p;
    return r;
}
int  RayoGetX(Rayo r)
{
    return r->x;
}
int  RayoGetX2(Rayo r)
{
    return r->x2;
}
int  RayoGetY(Rayo r)
{
    return r->y;
}
int  RayoGetH(Rayo r)
{
    return r->h;
}
int  RayoGetW(Rayo r)
{
    return r->w;
}

void RayoDibuja(Rayo r)
{
    r->x=PersonajeGetX(r->p)+(PersonajeGetW(r->p)/4);
    r->x2=PersonajeGetX(r->p)+PersonajeGetW(r->p)-(PersonajeGetW(r->p)/2.7);
    r->y=PersonajeGetY(r->p)-870;
    Pantalla_DibujaImagen(r->i, r->x,r->y,r->w,r->h);
    Pantalla_DibujaImagen(r->i, r->x2,r->y,r->w,r->h);
}

int RayoColision(Rayo r, int x, int y, int w, int h)
{
    if ((x<(r->x2+r->w))&&(x>(r->x-w))&&(y<(PersonajeGetY(r->p))))
    {
        return 1;
    }
    else return 0;
    ;
}

void RayoLibera(Rayo r)
{
    free(r);
}


