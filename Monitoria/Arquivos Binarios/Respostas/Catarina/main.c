/*
Neste exercício, o objetivo é desenvolver um programa em linguagem C que utilize
arquivos binários e Tipos Abstratos de Dados (TADs) para simular o funcionamento
básico de uma CPU.
Catarina Lemos
06/07/2026
*/

#include "cpu.h"
#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    Cpu *cpu = criaCpu();

    int nInst;
    scanf("%d\n", &nInst);

    Usuario *user = criaUsuario(nInst);

    FILE *arq = fopen ("bin.bin", "wb");

    adicionaInstrucao(user, arq);
    
    fclose (arq);

    FILE *arq2 = fopen ("bin.bin", "rb");
    realizaInstrucao(cpu, arq2, nInst);
    fclose (arq2);

    imprimeRegistradores(cpu);
    printf("\n");

    liberaUsuario(user);
    liberaCpu(cpu);

    return 0;
}