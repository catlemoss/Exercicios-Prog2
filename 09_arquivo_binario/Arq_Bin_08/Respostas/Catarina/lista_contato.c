#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_contato.h"
#include "vector.h"

struct ListaContato
{
    Vector *lista;
};

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato()
{
    tListaContato *lista = calloc (1, sizeof(*lista));
    if (lista == NULL) exit (1);

    lista->lista = VectorConstruct();

    return lista;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l)
{
    VectorDestroy(l->lista, (void (*)(DataType))DestruirContato);
    free (l);
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato)
{
    for (int i = 0; i < VectorSize(l->lista); i++)
    {
        if (ComparaNomeContato(VectorGet(l->lista, i), contato))
        {
            printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            return;
        }

        if (ComparaTelefoneContato(VectorGet(l->lista, i), contato))
        {
            printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            return;
        }
    }

    VectorPushBack(l->lista, contato);
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo)
{
    FILE *arq = fopen (nomeArquivo, "rb");
    if (arq == NULL) return;

    int qnt;
    fread (&qnt, sizeof(int), 1, arq);

    for (int i = 0; i < qnt; i++)
    {
        tContato *ctt = CarregarContato(arq);
        AdicionarContatoListaContato(l, ctt);
    }

    fclose (arq);
}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo)
{
    FILE *arq = fopen (nomeArquivo, "wb");
    if (arq == NULL) exit (1);

    int qnt = VectorSize(l->lista);
    fwrite(&qnt, sizeof(int), 1, arq);

    for (int i = 0; i < qnt; i++)
    {
        tContato *ctt = VectorGet(l->lista, i);
        SalvarContato(ctt, arq);
    }

    fclose (arq);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l)
{
    unsigned long int telefone;
    scanf("%lu\n", &telefone);

    for (int i = 0; i < VectorSize(l->lista); i++)
    {
        tContato *ctt = VectorGet(l->lista, i);

        if (GetTelefoneContato(ctt) == telefone)
        {
            ImprimirContato(ctt);
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l)
{
    char nome[100];
    scanf(" %99s\n", nome);

    for (int i = 0; i < VectorSize(l->lista); i++)
    {
        tContato *ctt = VectorGet(l->lista, i);

        if (strcmp(GetNomeContato(ctt), nome) == 0)
        {
            ImprimirContato(ctt);
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l)
{
    printf("Lista de contatos cadastrados\n");

    for (int i = 0; i < VectorSize(l->lista); i++)
    {
        tContato *ctt = VectorGet(l->lista, i);
        ImprimirContato(ctt);
        printf("\n");
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l)
{
    unsigned long int telefone;
    scanf("%lu\n", &telefone);

    for (int i = 0; i < VectorSize(l->lista); i++)
    {
        tContato *ctt = VectorGet(l->lista, i);
        if (GetTelefoneContato(ctt) == telefone)
        {
            DestruirContato(ctt);
            VectorRemove(l->lista, i);
            printf("Contato removido com sucesso\n");

            return;
        }
    }

    printf("Nao existe um contato cadastrado com esse numero de telefone\n");
}