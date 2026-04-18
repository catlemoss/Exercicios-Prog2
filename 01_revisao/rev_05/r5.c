/*
Um programa que leia o tamanho do mapa, a posição inicial, a posição final
e movimente o jogador procurando uma saída. 
Catarian Lemos
24/03/2026
*/

#include <stdio.h>

#define TAM 20
#define MAX_CAM 4

typedef struct
{
    int linha, coluna;
} tPosicao;

tPosicao lePosicao ()
{
    tPosicao p;
    scanf("%d %d", &p.linha, &p.coluna);
    return p;
}

void leMatriz (int mapa[TAM][TAM], int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }
}

tPosicao proximaPosicao (tPosicao atual, char direcao)
{
    tPosicao prox = atual;

    if (direcao == 'B') prox.linha++;
    else if (direcao == 'C') prox.linha--;
    else if (direcao == 'D') prox.coluna++;
    else if (direcao == 'E') prox.coluna--;

    return prox;
}

int podeAndar (int mapa[TAM][TAM], int linhas, int colunas,
                tPosicao atual, tPosicao fim,
                int visitados[TAM][TAM], char caminho[MAX_CAM], tPosicao caminhoFinal[TAM*TAM], int tam)
{

    int l = atual.linha - 1;
    int c = atual.coluna - 1;                   // para alinhar a matriz

    if (l < 0 || c < 0 || l >= linhas || c >= colunas) return 0; 
    // fora do mapa

    if (mapa[l][c] == 1 || visitados[l][c]) return 0;
    // parede ou visitado

    visitados[l][c] = 1;                        // marcar casa visitada

    caminhoFinal[tam] = atual;                  // guarda as coords andadas
    tam++;                                      // casinhas com as coords

    if (atual.linha == fim.linha && atual.coluna == fim.coluna) return tam;
    // chegou fim

    int andou = 0;

    for (int i = 0; i < MAX_CAM; i++)           // loop da prioridade de walking
    {
        tPosicao prox = proximaPosicao(atual, caminho[i]);

        int resultado = podeAndar(mapa, linhas, colunas, prox, fim, visitados,
                              caminho, caminhoFinal, tam);

        if (resultado != 0)                     // encontrou passagem
        {
            andou = 1;
            return resultado;
        }
    }

    if (!andou) return tam;                     // sem saida #sorry

    return 0;
}

int main ()
{
    int mapaLinha, mapaColuna;                  // tamanho do mapa
    scanf("%d %d", &mapaLinha, &mapaColuna);

    int mapa[TAM][TAM];
    leMatriz(mapa, mapaLinha, mapaColuna);      // le mapa

    tPosicao inicio, fim;
    inicio = lePosicao();                       // onde comecei
    fim = lePosicao();                          // onde devo terminar

    char caminho[5];                            // letras + \0
    scanf("%s", caminho);

    int i, j;                                   // para loops

    int visitados[TAM][TAM];
    for (i = 0; i < mapaLinha; i++)             // inicializa visitados
    { for (j = 0; j < mapaColuna; j++) { visitados[i][j] = 0; } }

    tPosicao caminhoFinal[TAM*TAM];             // um vetor de posicoes

    int tamanho = podeAndar (mapa, mapaLinha, mapaColuna,inicio, fim, visitados,
                    caminho, caminhoFinal, 0);

    for (i = 0; i < tamanho; i++)
    { printf("(%d,%d) ", caminhoFinal[i].linha, caminhoFinal[i].coluna); }

    return 0;
}