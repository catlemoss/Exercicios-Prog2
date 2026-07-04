/*
O exercício consiste em ler dados de uma imagem armazenados em um
arquivo binário e mostrar na tela um histograma dos pixels.
Catarina Lemos
04/07/2026
*/

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