#include "partida.h"
#include <string.h>
#include <stdio.h>

/*
Função que incializa os dados de uma partida e retorna o tPartida. 
@param char *time1: String com o nome do primeiro time da partida
@param char *time2: String com o nome do segundo time da partida
@param int pontosTime1: Inteiro com o número de pontos do primeiro time da partida
@param int pontosTime2: Inteiro com o número de pontos do segundo time da partida

@return tPartida: Retorna uma variável do tipo tPartida criada
*/
tPartida lerPartida(char *timeFora, char *timeCasa, int pontosTimeFora, int pontosTimeCasa)
{
    tPartida p;
    strcpy(p.nomeTimeFora, timeFora);
    strcpy(p.nomeTimeCasa, timeCasa);
    p.pontosTimeFora = pontosTimeFora;
    p.pontosTimeCasa = pontosTimeCasa;
    return p;
}

/*
Função que imprime todos os dados de uma partida (diferente dos casos de teste).

@param tFranquia f: Tipo tPartida a ser impresso
*/
void imprimePartida(tPartida p)
{
    printf("%s\n", p.nomeTimeFora);
    printf("%s\n", p.nomeTimeCasa);
    printf("%d\n", p.pontosTimeFora);
    printf("%d\n", p.pontosTimeCasa);
}

/*
Função que retorna os dados de uma partida. Caso o vencedor seja o time1 da partida, a
*/
void obtemDadosPartida(tPartida p, char *nomeTimeFora, char *nomeTimeCasa, int* pontosTimeFora, int* pontosTimeCasa)
{
    strcpy(nomeTimeFora, p.nomeTimeFora);
    strcpy(nomeTimeCasa, p.nomeTimeCasa);
    *pontosTimeFora = p.pontosTimeFora;
    *pontosTimeCasa = p.pontosTimeCasa;
}