#include "Personaje.h"
#include <stdlib.h>


struct PersonajeRep
{
    Imagen i, movi, izqi, deri;
    int x,y,w,h;
};


Personaje PersonajeCrea(Imagen i, Imagen movi, Imagen izqi, Imagen deri, int x, int y, int w, int h)
{
    Personaje p = malloc(sizeof(struct PersonajeRep));
    p->i = i;
    p->x = x;
    p->y = y;
    p->w = w;
    p->h = h;
    p->movi = movi;
    p->izqi = izqi;
    p->deri = deri;
    return p;
}


void PersonajeLibera(Personaje p)
{
    free(p);
}


void PersonajeMov(Personaje p,int sprint)
{

    if (Pantalla_TeclaPulsada(SDL_SCANCODE_W))
        PersonajeMueve(p, 0, -10);
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_S))
        PersonajeMueve(p, 0, 10);
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_A))
        PersonajeMueve(p, -10, 0);
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_D))
        PersonajeMueve(p, 10, 0);
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_W)&&sprint))
        PersonajeMueve(p, 0, -20);
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_S)&&sprint))
        PersonajeMueve(p, 0, 20);
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_A)&&sprint))
        PersonajeMueve(p, -20, 0);
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_D)&&sprint))
        PersonajeMueve(p,20,0);
}


void PersonajeMueve(Personaje p, int vx, int vy)
{
    p->x += vx;
    p->y += vy;
    if (p->x>Pantalla_Anchura()-p->w) p->x=Pantalla_Anchura()-p->w;
    if (p->x<0) p->x=0;
    if (p->y>Pantalla_Altura()-p->h) p->y=Pantalla_Altura()-p->h;
    if (p->y<0) p->y=0;
}



void PersonajeDibuja(Personaje p,int pmov)
{
    switch(pmov)
    {
    case(0):
        Pantalla_DibujaImagen(p->i,p->x,p->y,p->h,p->w);
        break;
    case(1):
        Pantalla_DibujaImagen(p->movi,p->x,p->y,p->h,p->w);
        break;
    case(2): //izq
        Pantalla_DibujaImagen(p->izqi,p->x,p->y,p->h,p->w);
        break;
    case(3)://der
        Pantalla_DibujaImagen(p->deri,p->x,p->y,p->h,p->w);
        break;
    };
};


int  PersonajeGetX(Personaje p)
{
    return p->x;
}


int  PersonajeGetY(Personaje p)
{
    return p->y;
}


int  PersonajeGetH(Personaje p)
{
    return p->h;
}


int  PersonajeGetW(Personaje p)
{
    return p->w;
}


void  PersonajeDibujaVida(int i,Imagen im)
{
    for(int x=0; x<i; x++) Pantalla_DibujaImagen(im,0+(50*x),0,50,50);
}


void NumAText(Imagen i0,Imagen i1,Imagen i2,Imagen i3,Imagen i4,Imagen i5,Imagen i6,Imagen i7,Imagen i8,Imagen i9,int n,int x,int y,int w, int h)
{
    int i=0;

    do
    {
        int ni = n % 10;
        n = n/10;
        switch(ni)
        {
        case(0):
            Pantalla_DibujaImagen(i0,x-(w/1.8*i),y,w,h);
            break;
        case(1):
            Pantalla_DibujaImagen(i1,x-(w/1.8*i),y,w,h);
            break;
        case(2):
            Pantalla_DibujaImagen(i2,x-(w/1.8*i),y,w,h);
            break;
        case(3):
            Pantalla_DibujaImagen(i3,x-(w/1.8*i),y,w,h);
            break;
        case(4):
            Pantalla_DibujaImagen(i4,x-(w/1.8*i),y,w,h);
            break;
        case(5):
            Pantalla_DibujaImagen(i5,x-(w/1.8*i),y,w,h);
            break;
        case(6):
            Pantalla_DibujaImagen(i6,x-(w/1.8*i),y,w,h);
            break;
        case(7):
            Pantalla_DibujaImagen(i7,x-(w/1.8*i),y,w,h);
            break;
        case(8):
            Pantalla_DibujaImagen(i8,x-(w/1.8*i),y,w,h);
            break;
        case(9):
            Pantalla_DibujaImagen(i9,x-(w/1.8*i),y,w,h);
            break;

        };
        i++;


    }
    while(n>0);
}

