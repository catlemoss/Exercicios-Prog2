#include "data.h"

#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int dia, mes, ano;
};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData()
{
    tData *d = malloc (sizeof(*d));
    if (d == NULL) exit (1);

    d->dia = -1;
    d->mes = -1;
    d->ano = -1;

    return d;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data)
{
    if (data == NULL) return;
    scanf("%d/%d/%d\n", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data)
{
    free (data);
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data)
{
    if (1 <= data->ano) return 1;
    if (1 <= data->mes && data->mes <= 12) return 1;
    if (1 <= data->dia && data->dia <= NumeroDiasMes(data)) return 1;

    return 0;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data)
{
    if (data->mes == 1) printf("Janeiro");
    else if (data->mes == 2) printf("Fevereiro");
    else if (data->mes == 3) printf("Marco");
    else if (data->mes == 4) printf("Abril");
    else if (data->mes == 5) printf("Maio");
    else if (data->mes == 6) printf("Junho");
    else if (data->mes == 7) printf("Julho");
    else if (data->mes == 8) printf("Agosto");
    else if (data->mes == 9) printf("Setembro");
    else if (data->mes == 10) printf("Outubro");
    else if (data->mes == 11) printf("Novembro");
    else if (data->mes == 12) printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data)
{
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data)
{
    return ((data->ano % 400 == 0) || (data->ano % 4 == 0 && data->ano % 100 != 0));
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data)
{
    if (data->mes == 1 || 
        data->mes == 3 || 
        data->mes == 5 || 
        data->mes == 7 || 
        data->mes == 8 || 
        data->mes == 10 || 
        data->mes == 12) 
        return 31;

    else if (data->mes == 4 || 
        data->mes == 6 || 
        data->mes == 9 || 
        data->mes == 11) 
        return 30;

    else if (data->mes == 2)
    {
        if (VerificaBissexto(data)) return 29;
        else return 28;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2)
{
    if (data1->ano < data2->ano) return 1;
    else if (data1->ano > data2->ano) return -1;
    else
    {
        if (data1->mes < data2->mes) return 1;
        else if (data1->mes > data2->mes) return -1;
        else
        {
            if (data1->dia < data2->dia) return 1;
            else if (data1->dia > data2->dia) return -1;
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
int CalculaDiasAteMes(tData* data)
{
    int totalDias = 0;

    tData *aux = CriaData();
    aux->ano = data->ano;

    for (aux->mes = 1; aux->mes < data->mes; aux->mes++)
    {
        totalDias += NumeroDiasMes(aux);
    }

    LiberaData(aux);

    return totalDias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2)
{
    int totalDias1 = 0;
    int totalDias2 = 0;

    tData *aux = CriaData();

    for (aux->ano = 1; aux->ano < data1->ano; aux->ano++)
    {
        if (VerificaBissexto(aux)) totalDias1 += 366;
        else totalDias1 += 365;
    }

    for (aux->ano = 1; aux->ano < data2->ano; aux->ano++)
    {
        if (VerificaBissexto(aux)) totalDias2 += 366;
        else totalDias2 += 365;
    }

    totalDias1 += CalculaDiasAteMes(data1);
    totalDias1 += data1->dia;

    totalDias2 += CalculaDiasAteMes(data2);
    totalDias2 += data2->dia;

    LiberaData(aux);

    if (totalDias1 > totalDias2) return totalDias1 - totalDias2;

    return totalDias2 - totalDias1;
}