#include "evento.h"

#include <stdio.h>
#include <string.h>

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos)
{
    char nome[50];
    int dia, mes, ano;

    if (*numEventos < MAX_EVENTOS)
    {
        scanf("%s\n", nome);
        scanf("%d %d %d\n", &dia, &mes, &ano);

        Evento eve;

        strcpy(eve.nome, nome);
        eve.dia = dia;
        eve.mes = mes;
        eve.ano = ano;

        eventos[*numEventos] = eve;
        (*numEventos)++;

        printf("Evento cadastrado com sucesso!\n");
    }

    else
    {
        printf("Limite de eventos atingido!\n");
    }
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos)
{
    if (*numEventos == 0) printf("Nenhum evento cadastrado.\n");
    else
    {
        printf("Eventos cadastrados:\n");

        for (int i = 0; i < *numEventos; i++)
        {
            printf("%d - %s - %d/%d/%d\n", 
                i, 
                eventos[i].nome, 
                eventos[i].dia,
                eventos[i].mes, 
                eventos[i].ano);
        }
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int ind;
    scanf("%d\n", &ind);

    if (*numEventos <= ind || ind < 0)
    {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = 0; i < *numEventos; i++)
    {
        if (i == ind)
        {
            int dia, mes, ano;
            scanf("%d %d %d\n", &dia, &mes, &ano);

            eventos[i].dia = dia;
            eventos[i].mes = mes;
            eventos[i].ano = ano;
        }
    }

    printf("Data modificada com sucesso!\n");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    if (0 <= *indiceA && *indiceA <= 10 && *indiceA < *numEventos &&
        0 <= *indiceB && *indiceB <= 10 && *indiceB < *numEventos)
    {
        Evento aux;

        aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;

        printf("Eventos trocados com sucesso!\n");
    }

    else printf("Indices invalidos!\n");
}