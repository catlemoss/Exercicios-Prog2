#ifndef _RETANGULO_H
#define _RETANGULO_H

typedef struct 
{
    float base, altura;
}tRetangulo;

tRetangulo leRetangulo(float base, float altura);
float getRetanguloBase(tRetangulo r);
float getRetanguloAltura(tRetangulo r);

#endif