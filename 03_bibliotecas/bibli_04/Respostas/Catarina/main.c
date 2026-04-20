/*
Continuando a partir da biblioteca desenvolvida no exercício
anterior, sua missão é implementar novas funcionalidades no gerenciamento de datas.
Catarina Lemos
20/04/2026 (aniversário do Kacchan!!!)
*/

#include <stdio.h>

#include "data.h"

int main ()
{
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (!verificaDataValida(dia, mes, ano))
    {
        printf("A data informada eh invalida\n");
        return 0;
    }

    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    if (verificaBissexto(ano)) printf("O ano informado eh bissexto\n");
    else printf("O ano informado nao eh bissexto\n");

    printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));

    printf("A data seguinte eh: ");
    imprimeProximaData(dia, mes, ano);

    return 0;
}
