#ifndef _TRIANGULO_H
#define _TRIANGULO_H

typedef struct 
{
    float base, altura;
}tTriangulo;

tTriangulo leTriangulo(float base, float altura);
float getTrianguloBase(tTriangulo t);
float getTrianguloAltura(tTriangulo t);

#endif