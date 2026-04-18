/*
Um jogo 2D de tiro ao alvo e você deseja verificar se um tiro acertou o alvo
Catarina Lemos
23/03/2026
*/

#include <stdio.h>

typedef struct
{
    float x, y, raio;
} tCirc;

tCirc leCirc ()
{
    tCirc c;
    scanf("%f %f %f", &c.x, &c.y, &c.raio);
    return c;
}

int acertou (tCirc c1, tCirc c2)
{
    float difX = c2.x - c1.x;
    float difY = c2.y - c1.y;
    float sumRaio = c2.raio + c1.raio;

    if ( (difX * difX)+ (difY * difY) <= (sumRaio * sumRaio)) return 1; // dentro
    else return 0; // fora
}

void imprimeResultado (tCirc c1, tCirc c2)
{
    if (acertou(c1, c2)) printf("ACERTOU\n");
    else printf("ERROU\n");
}

int main ()
{
    tCirc alvo, tiro; // circulos

    alvo = leCirc();
    tiro = leCirc();

    imprimeResultado(alvo, tiro);

    return 0;
}