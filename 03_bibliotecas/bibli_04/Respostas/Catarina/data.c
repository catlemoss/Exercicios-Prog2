#include <stdio.h>

#include "data.h"

int verificaDataValida(int dia, int mes, int ano)
{
    if (ano <= 0) return 0;
    if (mes < 1 || mes > 12) return 0;

    int dias = numeroDiasMes(mes, ano);

    if (dia < 1 || dia > dias) return 0;

    return 1;
}

void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

void imprimeMesExtenso(int mes)
{
    if (mes == 1) printf("Janeiro");
    else if (mes == 2) printf("Fevereiro");
    else if (mes == 3) printf("Marco");
    else if (mes == 4) printf("Abril");
    else if (mes == 5) printf("Maio");
    else if (mes == 6) printf("Junho");
    else if (mes == 7) printf("Julho");
    else if (mes == 8) printf("Agosto");
    else if (mes == 9) printf("Setembro");
    else if (mes == 10) printf("Outubro");
    else if (mes == 11) printf("Novembro");
    else if (mes == 12) printf("Dezembro");
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int verificaBissexto(int ano)
{
    if ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) return 1;
    else return 0;
}

int numeroDiasMes(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || 
        mes == 12)
    {
        return 31;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }

    if (mes == 2)
    {
        if (verificaBissexto(ano)) return 29;
        else return 28;
    }

    return 0;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2))
    {
        return 0;
    }
    
    if (ano1 > ano2) return 1;
    else if (ano1 < ano2) return -1;
    else
    {
        if (mes1 > mes2) return 1;
        else if (mes1 < mes2) return -1;
        else
        {
            if (dia1 > dia2) return 1;
            else if (dia1 < dia2) return -1;
            else return 0;
        }
    }
}

int calculaDiasAteMes(int mes, int ano)
{
    int dias = 0;

    for (int i = 1; i < mes; i++)
    {
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2))
    {
        return 0;
    }

    int numDias1 = dia1 + calculaDiasAteMes(mes1, ano1);
    int numDias2 = dia2 + calculaDiasAteMes(mes2, ano2);

    for (int i = 1; i < ano1; i++)
    {
        if (verificaBissexto(i)) numDias1 += 366;
        else numDias1 += 365;
    }

    for (int i = 1; i < ano2; i++)
    {
        if (verificaBissexto(i)) numDias2 += 366;
        else numDias2 += 365;
    }

    if (numDias1 > numDias2) return numDias1 - numDias2;
    else return numDias2 - numDias1;
}

void imprimeProximaData(int dia, int mes, int ano)
{
    dia++;

    if (dia > numeroDiasMes(mes, ano))
    {
        dia = 1;
        mes++;

        if (mes > 12)
        {
            mes = 1;
            ano++;
        }
    }

    printf("%02d/%02d/%04d\n", dia, mes, ano);
}