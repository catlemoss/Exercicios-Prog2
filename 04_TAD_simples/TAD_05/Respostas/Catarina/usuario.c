#include "usuario.h"

#include <stdio.h>
#include <string.h>

/*
typedef struct Usuario {
    char nome[50];
    char cpf[15];
} tUsuario;
*/

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15])
{
    tUsuario u;

    strcpy(u.nome, nome);
    strcpy(u.cpf, cpf);

    return u;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user)
{
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
    printf("\n");
}