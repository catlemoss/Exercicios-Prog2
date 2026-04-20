#include <stdio.h>

#include "temperature_conversor.h"

// C - K
float convert_celsius_to_kelvin(float temperature)
{
    return temperature + 273.15;
}

// C - F
float convert_celsius_to_fahrenheit(float temperature)
{
    return temperature * 9.0/5 + 32.0; 
}

// K - C
float convert_kelvin_to_celsius(float temperature)
{
    return temperature - 273.15;
}

// K - Fah
float convert_kelvin_to_fahrenheit(float temperature)
{
    return (temperature - 273.15) * 9.0/5 + 32.0;
}

// Fah - C
float convert_fahrenheit_to_celsius(float temperature)
{
    return (temperature - 32.0) * 5.0/9;
}

// Fah - K
float convert_fahrenheit_to_kelvin(float temperature)
{
    return (temperature - 32.0) * 5.0/9 + 273.15;
}

float convert_temperature(float temperature, float convert_func(float temperature))
{
    return convert_func(temperature);
}