/*
O exercício consiste em salvar os dados de uma imagem em um arquivo
binário.
Catarina Lemos
17/07/2026
*/

#include "imagem.h"

#include <stdio.h>

int main ()
{
    char nomeArq[20];
    scanf("%s", nomeArq);

    Imagem *img = LerImagem(nomeArq);

    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(img));
    ImprimirImagem(img);

    DestruirImagem(img);

    return 0;
}