#include "data.h"

#include <stdio.h>

/*
typedef struct Data {
    int dia;
    int mes;
    int ano; 
} tData;
*/

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano)
{
    tData d;

    d.dia = dia;
    d.mes = mes;
    d.ano = ano;

    return d;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data)
{
    if (data.mes < 1 || data.mes > 12) return 0;

    int dias = NumeroDiasMes(data);

    if (data.dia < 1 || data.dia > dias) return 0;

    if (data.ano <= 0) return 0;

    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data)
{
    if (data.mes == 1) printf("Janeiro");
    else if (data.mes == 2) printf("Fevereiro");
    else if (data.mes == 3) printf("Marco");
    else if (data.mes == 4) printf("Abril");
    else if (data.mes == 5) printf("Maio");
    else if (data.mes == 6) printf("Junho");
    else if (data.mes == 7) printf("Julho");
    else if (data.mes == 8) printf("Agosto");
    else if (data.mes == 9) printf("Setembro");
    else if (data.mes == 10) printf("Outubro");
    else if (data.mes == 11) printf("Novembro");
    else if (data.mes == 12) printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data)
{
    if (!VerificaDataValida(data)) return;

    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data)
{
    if ((data.ano % 400 == 0) || ((data.ano % 4 == 0) && (data.ano % 100 != 0))) return 1;
    else return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data)
{
    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    {
        return 31;
    }

    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
    {
        return 30;
    }

    if (data.mes == 2)
    {
        if (VerificaBissexto(data)) return 29;
        else return 28;
    }

    return 0;
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2)
{
    if (!VerificaDataValida(data1) || !VerificaDataValida(data2))
    {
        return 0;
    }
    
    if (data1.ano > data2.ano) return 1;
    else if (data1.ano < data2.ano) return -1;
    else
    {
        if (data1.mes > data2.mes) return 1;
        else if (data1.mes < data2.mes) return -1;
        else
        {
            if (data1.dia > data2.dia) return 1;
            else if (data1.dia < data2.dia) return -1;
            else return 0;
        }
    }
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data)
{
    int dias = 0;

    for (int i = 1; i < data.mes; i++)
    {
        tData dataAux = data;
        dataAux.mes = i;

        dias += NumeroDiasMes(dataAux);
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2)
{
    if (!VerificaDataValida(data1) || !VerificaDataValida(data2))
    {
        return 0;
    }

    int numDias1 = data1.dia + CalculaDiasAteMes(data1);
    int numDias2 = data2.dia + CalculaDiasAteMes(data2);

    for (int i = 1; i < data1.ano; i++)
    {
        tData dataAux;
        dataAux.ano = i;

        if (VerificaBissexto(dataAux)) numDias1 += 366;
        else numDias1 += 365;
    }

    for (int i = 1; i < data2.ano; i++)
    {
        tData dataAux;
        dataAux.ano = i;

        if (VerificaBissexto(dataAux)) numDias2 += 366;
        else numDias2 += 365;
    }

    if (numDias1 > numDias2) return numDias1 - numDias2;
    else return numDias2 - numDias1;
}