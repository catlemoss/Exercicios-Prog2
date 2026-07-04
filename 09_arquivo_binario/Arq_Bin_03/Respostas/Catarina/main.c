/*
O exercício consiste em salvar os dados de uma imagem em um arquivo
binário.
Catarina Lemos
02/07/2026
*/

#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char arq[100];
    scanf("%s", arq);

    Imagem *i = LerImagem(arq);
    if (i == NULL) return 1;

    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(i));
    ImprimirImagem(i);
    DestruirImagem(i);

    return 0;
}