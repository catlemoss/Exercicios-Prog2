#ifndef _PARTIDA_H
#define _PARTIDA_H

#include "constantes.h"

typedef struct 
{
    char nomeTimeFora[MAX_TIME_NOME];
    char nomeTimeCasa[MAX_TIME_NOME];
    int pontosTimeFora;
    int pontosTimeCasa;
} tPartida;

/*
Função que incializa os dados de uma partida e retorna o tPartida. 
@param char *time1: String com o nome do primeiro time da partida
@param char *time2: String com o nome do segundo time da partida
@param int pontosTime1: Inteiro com o número de pontos do primeiro time da partida
@param int pontosTime2: Inteiro com o número de pontos do segundo time da partida

@return tPartida: Retorna uma variável do tipo tPartida criada
*/
tPartida lerPartida(char *timeFora, char *timeCasa, int pontosTimeFora, int pontosTimeCasa);

/*
Função que imprime todos os dados de uma partida (diferente dos casos de teste).

@param tFranquia f: Tipo tPartida a ser impresso
*/
void imprimePartida(tPartida p);

/*
Função que retorna os dados de uma partida.
*/
void obtemDadosPartida(tPartida p, char *nomeTimeFora, char *nomeTimeCasa, int* pontosTimeFora, int* pontosTimeCasa);

#endif
