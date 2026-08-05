/*
Desenvolva um programa para gerenciar uma biblioteca de
livros parte 2.
Catarina Lemos
05/08/2025
*/

#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"

void menu()
{
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");
}

int main ()
{
    int operacoes;
    scanf("%d\n", &operacoes);

    menu();

    tBiblioteca *bibli = InicializarBiblioteca();

    int i = 0;

    while (i < operacoes)
    {
        int opcao;
        scanf("%d\n", &opcao);

        if (opcao == 1)
        {
            tLivros *livro = CriaLivro();
            LerLivro(livro);

            AdicionarLivroNaBiblioteca(bibli, livro);
            i++;
        }

        else if (opcao == 2)
        {
            char titulo[100];
            scanf("%s\n", titulo);

            RemoverLivroDaBiblioteca(bibli, titulo);
            i++;
        }

        else if (opcao == 3)
        {
            printf("\n");
            ListarLivrosDaBiblioteca(bibli);
            i++;
        }

        else
        {
            printf("Operacao invalida!\n");
            break;
        }
    }

    ApagaBiblioteca(bibli);

    return 0;
}