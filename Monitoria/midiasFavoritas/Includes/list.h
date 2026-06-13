#include <stdio.h>
#include <stdlib.h>
#include "media.h"

#define MAX_TAM_MIDIAS 5

typedef struct List List;

/**
 * @brief Constrói e inicializa uma nova lista vazia.
 * @return Ponteiro para a estrutura List instanciada.
 */
List *list_construct();

/**
 * @brief Insere um novo item genérico na lista.
 * Se o limite máximo da lista for atingido, a função gerenciará a inserção adequadamente baseada na implementação interna.
 * @param r Ponteiro para a lista onde o dado será inserido.
 * @param data Ponteiro genérico contendo a mídia específica.
 * @param print_fn Função utilizada para imprimir o dado inserido.
 * @param free_fn Função utilizada para desalocar o dado inserido.
 */
void list_media_insert(List *r, void *data, PrintFunction print_fn, FreeFunction free_fn);

/**
 * @brief Percorre a lista iterativamente e chama a impressão de todos os seus elementos formatados.
 * @param r Ponteiro para a estrutura List a ser impressa.
 */
void list_print(List *r);

/**
 * @brief Libera a memória de toda a lista e aciona o destrutor de todos os elementos armazenados nela.
 * @param r Ponteiro para a estrutura List a ser destruída.
 */
void list_free(List *r);