
#include "Colision.h"
#include <math.h>

int colision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    double c1x= x1+w1/2.0;
    double c1y= y1+h1/2.0;
    double c2x= x2+w2/2.00;
    double c2y= y2+h2/2.0;
    double r1=h1/2.0;
    double r2=h2/2.0;
    return (sqrt(pow(c1x-c2x,2) + pow(c1y-c2y,2))<r1+r2);
}
