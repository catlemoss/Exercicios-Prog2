/*
Uma biblioteca que forneça uma variedade
de funções para converter uma temperatura entre as escalas Celsius, Fahrenheit 451 e Kalvin.
Catarina Lemos
20/04/2026
*/

#include <stdio.h>

#include "temperature_conversor.h"

int main ()
{
    float temperatura;
    char escalaAtual, escalaDesired;
    scanf("%f %c %c", &temperatura, &escalaAtual, &escalaDesired);

    if (escalaDesired == 'c')
    {
        if (escalaAtual == 'f')
        {
            printf("Temperature: %.2fCº\n", convert_temperature(temperatura, 
                convert_fahrenheit_to_celsius));
        }

        else if (escalaAtual == 'k')
        {
            printf("Temperature: %.2fCº\n", convert_temperature(temperatura, convert_kelvin_to_celsius));
        }
    }

    if (escalaDesired == 'f')
    {
        if (escalaAtual == 'c')
        {
            printf("Temperature: %.2fFº\n", convert_temperature(temperatura, 
                convert_celsius_to_fahrenheit));
        }

        else if (escalaAtual == 'k')
        {
            printf("Temperature: %.2fFº\n", convert_temperature(temperatura, convert_kelvin_to_fahrenheit));
        }
    }

    if (escalaDesired == 'k')
    {
        if (escalaAtual == 'f')
        {
            printf("Temperature: %.2fK\n", convert_temperature(temperatura, 
                convert_fahrenheit_to_kelvin));
        }

        else if (escalaAtual == 'c')
        {
            printf("Temperature: %.2fK\n", convert_temperature(temperatura, convert_celsius_to_kelvin));
        }
    }

    return 0;
}