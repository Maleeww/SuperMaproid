#include "Ejercito.h"
#include "Disparo.h"
#include <stdlib.h>
#include "Enemigo.h"
#include "Colision.h"


struct EjercitoRep
{
    Enemigo e;
    Ejercito sig;
};

Ejercito EjercitoCrea(int nmax)
{
    Ejercito ej = malloc(sizeof(struct EjercitoRep));
    ej->sig = NULL;
    return ej;
}
void EjercitoLibera(Ejercito ej)
{
    while(ej->sig!=NULL)
    {
        Ejercito aux = ej->sig;
        ej->sig=ej->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    free(ej);
}
void EjercitoInserta(Ejercito ej, Imagen i,Imagen i1,Imagen i2,Imagen i3,Imagen i4,Imagen i5,Imagen i6,Imagen i7,Imagen i8,Imagen i9,Imagen i10,Imagen i11, int x, int y, int w, int h, int vx, int vy)
{
    Ejercito aux = malloc(sizeof(struct EjercitoRep));
    aux->e=EnemigoCrea(i,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,x,y,w,h,vx,vy);
    aux->sig=ej->sig;
    ej->sig=aux;
}

int EjercitoColision(Ejercito ej, int x, int y, int w, int h)
{
    while(ej->sig!=NULL)
    {
        if (colision(x,y,w,h,EnemigoGetX(ej->sig->e),EnemigoGetY(ej->sig->e),EnemigoGetW(ej->sig->e),EnemigoGetH(ej->sig->e)))
        {
            EnemigoAvanzaFrame(ej->sig->e);
            return 1;
        };
        if (EnemigoCompruebaFrame(ej->sig->e)==22)
        {
            Ejercito aux = ej->sig;
            ej->sig= ej->sig->sig;
            EnemigoLibera(aux->e);
            free(aux);
        }
        else
            ej = ej->sig;

    }
    return 0;
}

int EjercitoColisionRayo(Ejercito ej, Rayo r)
{
    while(ej->sig!=NULL)
    {
        if ((EnemigoCompruebaFrame(ej->sig->e)==0)&&RayoColision(r,EnemigoGetX(ej->sig->e),EnemigoGetY(ej->sig->e),EnemigoGetW(ej->sig->e),EnemigoGetH(ej->sig->e)))
        {
            EnemigoAvanzaFrame(ej->sig->e);
            return 1;
        };


        if (EnemigoCompruebaFrame(ej->sig->e)==22)
        {
            Ejercito aux = ej->sig;
            ej->sig= ej->sig->sig;
            EnemigoLibera(aux->e);
            free(aux);
        }
        else
            ej = ej->sig;
    }
    return 0;
}
void EjercitoDibuja(Ejercito ej)
{
    while(ej->sig!=NULL)
    {
        EnemigoDibuja(ej->sig->e);
        ej=ej->sig;
    }
}
void EjercitoMueve(Ejercito ej)
{
    while (ej->sig!=NULL)
    {

        EnemigoMueve(ej->sig->e);
        ej=ej->sig;

    }

};

void  EjercitoDibujaVida(int i,Imagen im)
{
    for(int x=1; x<i; x++)
        Pantalla_DibujaImagen(im,Pantalla_Anchura()-(50*x),0,50,50);
}

