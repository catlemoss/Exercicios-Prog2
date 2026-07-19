#include <stdio.h>
#include <stdlib.h>

#include "lista_contato.h"

// testando coisas novas
void menu()
{
    printf("1 - Cadastrar contato\n");
    printf("2 - Remover contato\n");
    printf("3 - Realizar busca\n");
    printf("4 - Exibir todos os contatos\n");
    printf("0 - Sair da lista de contatos\n");
    printf("Opcao escolhida: \n");
}

void submenu()
{
    printf("\n1 - Buscar pelo nome\n");
    printf("2 - Buscar pelo numero de telefone\n");
    printf("Opcao escolhida: \n");
}

int main ()
{
    char nomeArq[100];
    scanf("%99s\n", nomeArq);

    tListaContato *lista = CriarListaContato();
    CarregarListaContato(lista, nomeArq);

    int opc;
    while (1)
    {
        menu();
        scanf("%d\n", &opc);

        if (opc == 1)
        {
            tContato *ctt = LeContato();
            AdicionarContatoListaContato(lista, ctt);
        }

        else if (opc == 2)
        {
            RemoverContatoListaContato(lista);
        }

        else if (opc == 3)
        {
            submenu();

            int newOpc;
            scanf("%d\n", &newOpc);

            if (newOpc == 1)
            {
                BuscarPorNomeListaContato(lista);
            }

            else if (newOpc == 2)
            { 
                BuscarPorNumeroTelefoneListaContato(lista);
            }
        }

        else if (opc == 4)
        {
            ImprimirListaContato(lista);
        }

        else if (opc == 0) break;
    }

    scanf("\n%99s", nomeArq);
    
    SalvarListaContato(lista, nomeArq);
    DestruirListaContato(lista);

    return 0;
}
