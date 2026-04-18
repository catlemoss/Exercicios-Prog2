#include "esfera_utils.h"

// volume total
float calcula_volume (float R)
{
    return 4.0/3.0 * PI * R*R*R;
}

// area superficial
float calcula_area (float R)
{
    return 4 * PI * R*R;
}