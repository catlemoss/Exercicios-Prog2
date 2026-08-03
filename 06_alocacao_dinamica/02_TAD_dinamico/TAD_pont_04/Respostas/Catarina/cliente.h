#ifndef _Cliente_H_
#define _Cliente_H_

#include "aluno.h"

typedef struct Cliente {
    tAluno **alunos;
    int qnt;
    int max;
} tCliente;

tCliente *tClienteConstruct();

void tClientePushBack(tCliente *c, tAluno *aluno);

tAluno *tClienteGet(tCliente *c, int i);

int tClienteSize(tCliente *c);

void tClienteOrganize(tCliente *c);

void tClienteDestroy(tCliente *c);

#endif
