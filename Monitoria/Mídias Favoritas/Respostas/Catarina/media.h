#ifndef MIDIA_H 
#define MIDIA_H

typedef void (*PrintFunction)(void* data);

typedef void (*FreeFunction)(void* data);

typedef struct Media Media;

/**
 * @brief Constrói uma nova estrutura de mídia encapsulando os ponteiros e funções recebidos.
 * Esta função é agnóstica ao tipo específico, servindo como invólucro para Músicas, Filmes ou Jogos.
 * @param dado Ponteiro genérico (void*) para o item específico.
 * @param print_fn Função associada para imprimir o dado genérico.
 * @param free_fn Função associada para liberar a memória do dado genérico.
 * @return Ponteiro para a estrutura Media alocada.
 */
Media *media_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn);

/**
 * @brief Invoca a função de impressão interna contida na estrutura Media.
 * @param m Ponteiro para a estrutura Media que será impressa.
 */
void media_print(Media* m);

/**
 * @brief Invoca a função de liberação interna do dado e desaloca a estrutura Media.
 * @param m Ponteiro para a estrutura Media a ser destruída.
 */
void media_free(Media* m);

#endif