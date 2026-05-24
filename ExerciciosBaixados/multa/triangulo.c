#include "triangulo.h"

tTriangulo leTriangulo(float base, float altura)
{
    tTriangulo t;
    t.base = base;
    t.altura = altura;
    return t;
}

float getTrianguloBase(tTriangulo t)
{
    return(t.base);
}

float getTrianguloAltura(tTriangulo t)
{
    return(t.altura);
}