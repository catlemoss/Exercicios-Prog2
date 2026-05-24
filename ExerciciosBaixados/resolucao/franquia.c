#include "franquia.h"
#include <string.h>

/*
Função que cria os dados de uma franquia e retorna o tFranquia. 
@param char *nomeFranquia: String com o nome da franquia criada
@param char *nomeConferencia: String com o nome da conferência criada

@return tFranquia: Retorna uma variável do tipo tFranquia criada
*/
tFranquia lerFranquia(char *nomeFranquia, char *nomeConferencia)
{
    tFranquia f;
    strcpy(f.nome, nomeFranquia);
    strcpy(f.conferencia, nomeConferencia);
    f.vitoriaCasa = f.vitoriaFora = f.derrotaCasa = f.derrotaFora = f.nPartidasJogadas = 0;
    return f;
}

/*
Função que imprime todos os dados de uma franquia (diferente dos casos de teste).

@param tFranquia f: Tipo tFranquia a ser impresso
*/
void imprimeFranquia(tFranquia f)
{
    printf("%s\n", f.nome);
    printf("%s\n", f.conferencia);
    printf("%d\n", f.vitoriaCasa);
    printf("%d\n", f.vitoriaFora);
    printf("%d\n", f.derrotaCasa);
    printf("%d\n", f.derrotaFora);
    printf("%d\n", f.nPartidasJogadas);
}

/*
Função que atualiza os dados de franquia a partir de dados de uma partida jogada. 
Deve-se obter os dados da partida, percorrer todos os times das franquias passadas e verificar 
quais jogadores ganharam, perderam, quais foram suas pontuações e se a vitória foi em casa ou 
fora dela. Por fim, os times relacionados na partida devem ter seus dados atualizados

@param tFranquia *franquias: Vetor de tFranquias
@param int qtdFranquias: Inteiro com o tamanho de franquias cadastradas
@param tPartida p: Nova partida a ser utilizada para atualizar dados de times das franquias
*/
void insereDadosPartida(tFranquia *franquias, int qtdFranquias, tPartida p)
{
    char nomeJogadorFora[MAX_TIME_NOME], nomeJogadorCasa[MAX_TIME_NOME];
    int pontosJogadorCasa, pontosJogadorFora;

    obtemDadosPartida(p, nomeJogadorFora, nomeJogadorCasa, &pontosJogadorFora, &pontosJogadorCasa);
    for(int i=0; i<qtdFranquias; i++)
    {
        //fora de casa
        if(strcmp(franquias[i].nome, nomeJogadorFora) == 0)
            if(pontosJogadorFora > pontosJogadorCasa)
            {
                franquias[i].vitoriaFora++;
                franquias[i].nPartidasJogadas++;
            }
            else
            {
                franquias[i].derrotaFora++;
                franquias[i].nPartidasJogadas++;
            }

        //em casa    
        if(strcmp(franquias[i].nome, nomeJogadorCasa) == 0)
            if(pontosJogadorCasa > pontosJogadorFora)
            {
                franquias[i].vitoriaCasa++;
                franquias[i].nPartidasJogadas++;
            }
            else
            {
                franquias[i].derrotaCasa++;
                franquias[i].nPartidasJogadas++;
            }
    }
}

/*
Função que imprime os dados de das franquias de acordo com os casos de teste de saída.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosFranquia(tFranquia *franquias, int qtdFranquias)
{
    for(int i=0; i<qtdFranquias; i++)
    {
        char conf[3];
        if(strcmp(franquias[i].conferencia, "LESTE") == 0)
            strcpy(conf, "CL");
        else
        strcpy(conf, "CO");

        if((franquias[i].derrotaFora + franquias[i].derrotaCasa + franquias[i].vitoriaFora + franquias[i].vitoriaCasa) > 0)
            printf("%s [%s] %d %d %.2f %d %d\n", franquias[i].nome, conf, 
                (franquias[i].vitoriaCasa + franquias[i].vitoriaFora), 
                (franquias[i].derrotaCasa + franquias[i].derrotaFora),
                (100.00 * (float)(franquias[i].vitoriaCasa + franquias[i].vitoriaFora)/
                (franquias[i].vitoriaCasa + franquias[i].vitoriaFora + franquias[i].derrotaCasa
                    + franquias[i].derrotaFora)), franquias[i].vitoriaFora, franquias[i].vitoriaCasa);
        else
        printf("%s [%s] %d %d 0.00 %d %d\n", franquias[i].nome, conf, 
            (franquias[i].vitoriaCasa + franquias[i].vitoriaFora), 
            (franquias[i].derrotaCasa + franquias[i].derrotaFora),
            franquias[i].vitoriaFora, franquias[i].vitoriaCasa);
    }
}

/*
Função que imprime os dados de uma conferência de acordo com os casos de teste de saída.
Deve-se calcular os valores de vitórias e derrotas dentro e fora de casa para cada franquia 
de cada conferência (LESTE e OESTE), imprimindo as estatísticas ao final da chamada da função.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosConferencia(tFranquia *franquias, int qtdFranquias)
{
    int totalVitoriasCL = 0, totalVitoriasCO = 0, totalDerrotasCL = 0, totalDerrotasCO = 0;
    
    for(int i=0; i<qtdFranquias; i++)
    {
        if(strcmp(franquias[i].conferencia,"OESTE") == 0)
        {
            totalVitoriasCO+= franquias[i].vitoriaCasa + franquias[i].vitoriaFora;
            totalDerrotasCO+= franquias[i].derrotaCasa + franquias[i].derrotaFora;
        }
        else
        {
            totalVitoriasCL+= franquias[i].vitoriaCasa + franquias[i].vitoriaFora;
            totalDerrotasCL+= franquias[i].derrotaCasa + franquias[i].derrotaFora;
        }
    }

    if((totalVitoriasCL + totalDerrotasCL) > 0)
    {
        printf("LESTE %d %d %.2f\n", totalVitoriasCL, totalDerrotasCL, 
            (100.00 * ((float)totalVitoriasCL/(totalVitoriasCL + totalDerrotasCL))));
    }
        
    else
        printf("LESTE %d %d 0.00\n", totalVitoriasCL, totalDerrotasCL);
    
    if((totalVitoriasCO + totalDerrotasCO) > 0)
    {
        printf("OESTE %d %d %.2f\n", totalVitoriasCO, totalDerrotasCO, 
            (100.00 * ((float)totalVitoriasCO/(totalVitoriasCO + totalDerrotasCO))));
    }

    else
    printf("OESTE %d %d 0.00\n", totalVitoriasCO, totalDerrotasCO);
}