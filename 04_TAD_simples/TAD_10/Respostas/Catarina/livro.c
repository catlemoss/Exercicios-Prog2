#include "livro.h"

#include <stdio.h>
#include <string.h>

/*
// Estrutura que representa um livro
typedef struct {
    char titulo[100]; // Título do livro
    char autor[50];   // Autor do livro
    int anoPublicacao; // Ano de publicação do livro
} tLivros;
*/

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro()
{
    char titulo[100];
    char autor[50];
    int anoPubli;

    scanf("%s\n", titulo);
    scanf("%s\n", autor);
    scanf("%d\n", &anoPubli);

    tLivros l;

    strcpy(l.titulo, titulo);
    strcpy(l.autor, autor);
    l.anoPublicacao = anoPubli;

    return l;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro)
{
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}