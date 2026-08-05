#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"
/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro()
{
    tLivros *l = malloc (sizeof(*l));
    if (l == NULL) exit(1);

    l->titulo = NULL;
    l->autor = NULL;

    l->anoPublicacao = -1;

    return l;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro)
{
    char titulo[100];
    char autor[50];
    int anoPubli;

    scanf("%s\n", titulo);
    scanf("%s\n", autor);
    scanf("%d\n", &anoPubli);

    livro->titulo = malloc ((strlen(titulo)+1) * sizeof(char));
    livro->autor = malloc ((strlen(autor)+1) * sizeof(char));

    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    livro->anoPublicacao = anoPubli;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro)
{
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->anoPublicacao);
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro)
{
    free (livro->titulo);
    free (livro->autor);
    free (livro);
}