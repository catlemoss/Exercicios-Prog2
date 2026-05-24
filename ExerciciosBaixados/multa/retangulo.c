#include "retangulo.h"

tRetangulo leRetangulo(float base, float altura)
{
    tRetangulo r;
    r.base = base;
    r.altura = altura;
    return r;
}

float getRetanguloBase(tRetangulo r)
{
    return(r.base);
}

float getRetanguloAltura(tRetangulo r)
{
    return(r.altura);
}