/*
Um código que utiliza recursão para imprimir palavras de trás para frente.
Catarina Lemos
06/04/2026
*/

#include <stdio.h>

#define MAX_CHAR 1000

// inverte UMA palavra
void ImprimeInvertido(char string[], int inicio, int fim)
{
    if (fim < inicio) return;                           // parada

    printf("%c", string[fim]);

    ImprimeInvertido(string, inicio, fim - 1);
}

// achar palavra para inverter
void processaFrase(char frase[], int i)
{
    if (frase[i] == '\0' || frase[i] == '\n') return;   // parada

    int inicio = i;

    while (frase[i] != ' ' && frase[i] != '\0' && frase[i] != '\n')
    {
        i++;
    }                                                   // acha fim da palavra

    int fim = i - 1;

    ImprimeInvertido(frase, inicio, fim);               // imprime palavra found

    if (frase[i] == ' ')                                // espaço s'il te plait
    {
        printf(" ");
        processaFrase(frase, i + 1);
    }
}

int main()
{
    char frase[MAX_CHAR];
    fgets(frase, MAX_CHAR, stdin);                      // para ler frases com espaço

    processaFrase(frase, 0);
    printf("\n");

    return 0;
}