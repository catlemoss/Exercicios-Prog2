#include "histograma.h"

#include <stdio.h>

int main ()
{
    char caminho[1024];
    int nIntervalos;

    scanf("%s", caminho);
    scanf("%d", &nIntervalos);

    Imagem *img = LerImagem(caminho);
    Histograma *h = CalcularHistograma(img, nIntervalos);

    MostrarHistograma(h);
    DestruirHistograma(h);
    DestruirImagem(img);

    return 0;
}