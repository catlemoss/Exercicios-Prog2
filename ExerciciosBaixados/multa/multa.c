#include "multa.h"

float multaCircular(tCirculo c)
{
    float multa = (getCirculoRaio(c) * getCirculoRaio(c) * PI)/HECTARE;
    return(multa*6000.00); 
}
float multaRetangular(tRetangulo r)
{
    float multa = (getRetanguloAltura(r) * getRetanguloBase(r))/HECTARE;
    return(multa*8000.00);
}
float multaTriangular(tTriangulo t)
{
    float multa = ((getTrianguloAltura(t) * getTrianguloBase(t))/2)/HECTARE;
    return(multa*7000.00);
}
