#include "pacote.h"

#include <stdio.h>
#include <stdlib.h>

struct pacote
{
    Type tipoMsg;
    int tamMsg;
    void *mensagem;
    int soma;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *p = malloc (sizeof (tPacote));
    if (p == NULL) return NULL;

    p->tipoMsg = type;
    p->tamMsg = numElem;
    p->soma = 0;

    if (type == CHAR)
    {
        p->mensagem = malloc (numElem * sizeof (char));
    }
    
    else if (type == INT)
    {
        p->mensagem = malloc (numElem * sizeof (int));
    }

    else p->mensagem = NULL;
    
    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac)
{
    free (pac->mensagem);
    free (pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac)
{
    if (pac->tipoMsg == CHAR)
    {
        char *vet = (char *) pac->mensagem;

        scanf(" ");

        for (int i = 0; i < pac->tamMsg; i++)
        {
            scanf("%c", &vet[i]);
        }
    }
    
    else if (pac->tipoMsg == INT)
    {
        int *vet = (int *) pac->mensagem;

        for (int i = 0; i < pac->tamMsg; i++)
        {
            scanf("%d", &vet[i]);
        }
    }

    CalculaSomaVerificacaoPacote(pac);
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac)
{
    printf("%d ", pac->soma);

    if (pac->tipoMsg == CHAR)
    {
        char *vet = (char *) pac->mensagem;

        for (int i = 0; i < pac->tamMsg; i++)
        {
            printf("%c", vet[i]);
        }
    }
    
    else if (pac->tipoMsg == INT)
    {
        int *vet = (int *) pac->mensagem;

        for (int i = 0; i < pac->tamMsg; i++)
        {
            printf("%d", vet[i]);
        }
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    if (pac->tipoMsg == CHAR)
    {
        char *vet = (char *) pac->mensagem;

        for (int i = 0; i < pac->tamMsg; i++)
        {
            pac->soma += vet[i];
        }
    }
    
    else if (pac->tipoMsg == INT)
    {
        int *vet = (int *) pac->mensagem;

        for (int i = 0; i < pac->tamMsg; i++)
        {
            pac->soma += vet[i];
        }
    }
}