#include "loja.h"

#include <stdio.h>
#include <string.h>

/*
#define MAX_VENDEDORES 10

typedef struct Loja {
    int id;                                 < ID da loja
    int totalVendedores;                    < Número total de vendedores da loja
    float aluguel;                          < Valor do aluguel da loja
    float lucro;                            < Lucro da loja
    tVendedor vendedores[MAX_VENDEDORES];   < Vetor de vendedores da loja
} tLoja;
*/

/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja AbreLoja(int id, float aluguel)
{
    tLoja l;

    l.id =  id;
    l.aluguel = aluguel;

    l.totalVendedores = 0;
    l.lucro = 0;

    return l;
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja loja, int id)
{
    return loja.id == id;
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
tLoja ContrataVendedor(tLoja loja, tVendedor vendedor)
{
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;

    return loja;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
tLoja RegistraVenda(tLoja loja, char nome[50], float valor)
{
    for (int i = 0; i < loja.totalVendedores; i++)
    {
        if (VerificaNomeVendedor(loja.vendedores[i], nome))
        {
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            break;
        }
    }

    return loja;
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
tLoja CalculaLucro(tLoja loja)
{
    float totalVendido = 0;
    float totalRecebido = 0;

    for (int i = 0; i < loja.totalVendedores; i++)
    {
        totalVendido += GetTotalVendido(loja.vendedores[i]);
        totalRecebido += GetTotalRecebido(loja.vendedores[i]);
    }

    loja.lucro = totalVendido - (totalRecebido + loja.aluguel);

    return loja;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja loja)
{
    loja = CalculaLucro(loja);

    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
	
    for (int i = 0; i < loja.totalVendedores; i++)
    {
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}