#include <stdio.h>
#include "multa.h"

int main()
{
    int nTerrenos;
    scanf("%d\n", &nTerrenos);

    for(int i=0; i<nTerrenos; i++)
    {
        char tipo;
        scanf("%c\n", &tipo);

        if(tipo == 'C')
        {
            float raio;
            scanf("%f\n", &raio);
            tCirculo c = leCirculo(raio);
            float multa = multaCircular(c);
            printf("Preço: %.2f\n", multa);
        }
        else 
        {
            if(tipo == 'R')
            {
                float base, altura;
                scanf("%f %f\n", &base, &altura);
                tRetangulo r = leRetangulo(base, altura);
                float multa = multaRetangular(r);
                printf("Preço: %.2f\n", multa);
            }
            else
            {
                float base, altura;
                scanf("%f %f\n", &base, &altura);
                tTriangulo t = leTriangulo(base, altura);
                float multa = multaTriangular(t);
                printf("Preço: %.2f\n", multa);
            }
        }
    }
    return 0;
}