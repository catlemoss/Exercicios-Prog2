#ifndef _FRANQUIA_H
#define _FRANQUIA_H

#include <stdio.h>
#include <string.h>
#include "constantes.h"
#include "partida.h"

typedef struct 
{
    char nome[MAX_TIME_NOME];
    char conferencia[MAX_CONF_NOME];
    int vitoriaCasa;
    int vitoriaFora;
	int derrotaCasa;
    int derrotaFora;
    int nPartidasJogadas;
} tFranquia;

/*
Função que cria os dados de uma franquia e retorna o tFranquia. 
@param char *nomeFranquia: String com o nome da franquia criada
@param char *nomeConferencia: String com o nome da conferência criada

@return tFranquia: Retorna uma variável do tipo tFranquia criada
*/
tFranquia lerFranquia(char *nomeFranquia, char *nomeConferencia);

/*
Função que imprime todos os dados de uma franquia (diferente dos casos de teste).

@param tFranquia f: Tipo tFranquia a ser impresso
*/
void imprimeFranquia(tFranquia f);

/*
Função que atualiza os dados de franquia a partir de dados de uma partida jogada. 
Deve-se obter os dados da partida, percorrer todos os times das franquias passadas e verificar 
quais jogadores ganharam, perderam, quais foram suas pontuações e se a vitória foi em casa ou 
fora dela. Por fim, os times relacionados na partida devem ter seus dados atualizados

@param tFranquia *franquias: Vetor de tFranquias
@param int qtdFranquias: Inteiro com o tamanho de franquias cadastradas
@param tPartida p: Nova partida a ser utilizada para atualizar dados de times das franquias
*/
void insereDadosPartida(tFranquia *franquias, int qtdFranquias, tPartida p);

/*
Função que imprime os dados de das franquias de acordo com os casos de teste de saída.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosFranquia(tFranquia *franquias, int qtdFranquias);

/*
Função que imprime os dados de uma conferência de acordo com os casos de teste de saída.
Deve-se calcular os valores de vitórias e derrotas dentro e fora de casa para cada franquia 
de cada conferência (LESTE e OESTE), imprimindo as estatísticas ao final da chamada da função.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosConferencia(tFranquia *franquias, int qtdFranquias);

#endif
