#ifndef _SUPERMERCADO_H
#define _SUPERMERCADO_H

#include "produto.h"

typedef struct Supermercado Supermercado;

/**
 * @brief Cria uma nova instância de Supermercado e inicializa produto como NULL, numProdutos como 0 e lucro como 0.
 * 
 * @return Supermercado* Ponteiro para a nova instância de Supermercado criada ou encerra o programa caso não haja memória suficiente.
 */
Supermercado* CriarSupermercado ();

/**
 * @brief Destrói uma instância de Supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser destruída.
 */
void LiberaSupermercado (Supermercado* s);

/**
 * @brief Verifica se um produto está cadastrado no supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser verificada.
 * @param codigo Código do produto a ser verificado.
 * @return int 1 se o produto está cadastrado, 0 caso contrário.
 */
int VerificarProdutoCadastrado (Supermercado* s, int codigo);

/**
 * @brief Lê os dados de cadastro de um produto e o cadastra no supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 */
void LerCadastroSupermercado(Supermercado* s);

/**
 * @brief Cadastra um novo produto no supermercado caso ele não esteja cadastrado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 * @param p Ponteiro para o produto a ser cadastrado.
 */
void CadastrarProdutoSupermercado(Supermercado *s, Produto *p);

/**
 * @brief Compra um produto do supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 * @param codigo código do produto a ser alugado.
 */
void ComprarProdutoSupermercado(Supermercado* s, int codigo);

/**
 * @brief Lê a compra de um conjunto de produtos a partir da entrada padrão e os compra no supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 */
void LerCompraSupermercado(Supermercado* s);

/**
 * @brief Adiciona a qtdFornecida do produto ao estoque do supermercado
 * 
 * @param s Ponteiro para a instancia de Supermercado a ser atualizada
 * @param codigo codigo do produto ja cadastrado no supermercado
 * @param qtdFornecida quantidade do produto fornecida ao supermercado
 */
void FornecerProdutoSupermercado(Supermercado* s, int codigo, int qtdFornecida);

/**
 * @brief Le o fornecimento de um quantidade de um produto ja cadastrado e o fornece pro supermercado 
 * 
 * @param s Ponteiro para a instancia de Supermercado a ser atualizada
 */
void LerFornecimento(Supermercado* s);

/**
 * @brief Ordena os produtos cadastrados no supermercado por ordem alfabética.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 */
void OrdenarProdutosSupermercado(Supermercado* s);

/**
 * @brief Consulta o estoque de produtos do supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser consultada.
 */
void ConsultarEstoqueSupermercado (Supermercado* s);

/**
 * @brief Consulta o lucro do supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser consultada.
 */
void ConsultarLucroSupermercado (Supermercado* s);

#endif