#include "Estrella.h"
#include "Galaxia.h"
#include <stdlib.h>
#include "Colision.h"

struct GalaxiaRep
{
    Estrella * e;
    int n,nmax;
};

Galaxia GalaxiaCrea(int nmax)
{
    Galaxia g = malloc(sizeof(struct GalaxiaRep));
    g->e = malloc(nmax*sizeof(Estrella));
    g->n = 0;
    g->nmax = nmax;
    return g;
}
void GalaxiaLibera(Galaxia g)
{
    for(int i=0; i<g->n; i++)
    {
        EstrellaLibera(g->e[i]);
    }
    free(g->e);
    free(g);
}
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h)
{
    if (g->n < g->nmax)
    {
        g->e[g->n] = EstrellaCrea(i,x,y,w,h);
        g->n++;
    }
}
void GalaxiaDibuja(Galaxia g)
{
//for para llamar a Estrelladibuja y recorrer el array
    for(int i=0; i<g->n; i++)
    {
        EstrellaDibuja(g->e[i]);
    }
}
int GalaxiaColision(Galaxia g, int x, int y, int w, int h)
{
//cada estrella que colisione con el pj la borra y devuelve el n de estrellas con el que colisiona
    int i=0;
    int c=0;
    while(i<g->n)
    {
        if (colision(x,y,w,h,EstrellaGetX(g->e[i]),EstrellaGetY(g->e[i]),EstrellaGetW(g->e[i]),EstrellaGetH(g->e[i])))
        {
            EstrellaLibera(g->e[i]);
            g->e[i] = g->e[g->n-1];
            c++;
            g->n--;
        }
        else
        {
            i++;
        }
    }
    return c;
}
