#include "circulo.h"

tCirculo leCirculo(float r)
{
    tCirculo c;
    c.raio = r;
    return c;
}
float getCirculoRaio(tCirculo c)
{
    return(c.raio);
}