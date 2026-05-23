/*
Desenvolva um programa para gerenciar uma biblioteca de livros.
Catarina Lemos
23/05/2026
*/

#include "biblioteca.h"

#include <stdio.h>

int main ()
{
    int operacoes;
    scanf("%d\n", &operacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");

    tBiblioteca bibli = inicializarBiblioteca();
    tLivros livro;

    int i = 0;

    while (i < operacoes)
    {
        int opcao;
        scanf("%d\n", &opcao);

        if (opcao == 1)
        {
            livro = lerLivro();
            bibli = adicionarLivroNaBiblioteca(bibli, livro);
            i++;
        }

        else if (opcao == 2)
        {
            char titulo[100];
            scanf("%s\n", titulo);

            bibli = removerLivroDaBiblioteca(bibli, titulo);
            i++;
        }

        else if (opcao == 3)
        {
            printf("\n");
            listarLivrosDaBiblioteca(bibli);
            i++;
        }

        else
        {
            printf("Operacao invalida!\n");
            break;
        }
    }

    return 0;
}