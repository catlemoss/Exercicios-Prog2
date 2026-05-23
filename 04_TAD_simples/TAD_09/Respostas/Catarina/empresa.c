#include "empresa.h"
#include "funcionario.h"

#include <stdio.h>

/*
typedef struct empresa {
    int id;
    tFuncionario funcionarios[20];
    int qtdFuncionarios;
} tEmpresa;
*/

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id)
{
    tEmpresa e;

    e.id = id;
    e.qtdFuncionarios = 0;

    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa()
{
    int id, nFunc;

    scanf("%d %d\n", &id, &nFunc);

    tEmpresa e = criaEmpresa(id);

    for (int i = 0; i < nFunc; i++)
    {
        e = contrataFuncionarioEmpresa(e, leFuncionario());
    }

    return e;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    for (int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        if (getIdFuncionario(empresa.funcionarios[i]) == getIdFuncionario(funcionario))
        {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));

            return empresa;
        }
    }

    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    empresa.qtdFuncionarios++;

    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa)
{
    printf("Empresa %d:\n", empresa.id);

    for (int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}
