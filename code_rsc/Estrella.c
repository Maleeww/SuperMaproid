
#include "Estrella.h"
#include <stdlib.h>

struct EstrellaRep
{
    Imagen i;
    int x,y,w,h;
};
Estrella EstrellaCrea(Imagen i,int x, int y, int w, int h)
{
    Estrella e = malloc(sizeof(struct EstrellaRep));
    e->i = i;
    e->x = x;
    e->y = y;
    e->w = w;
    e->h = h;
    return e;
}
void EstrellaLibera(Estrella e)
{
    free(e);
}

void EstrellaDibuja(Estrella e)
{
    Pantalla_DibujaImagen(e->i,e->x,e->y,e->h,e->w);
};
int  EstrellaGetX(Estrella e)
{
    return e->x;
}
int  EstrellaGetY(Estrella e)
{
    return e->y;
}
int  EstrellaGetH(Estrella e)
{
    return e->h;
}
int  EstrellaGetW(Estrella e)
{
    return e->w;
}

