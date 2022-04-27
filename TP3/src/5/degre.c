#include "degre.h"

float cel2kel(float cel)
{
    return cel + 273;
}

float cel2fah(float cel)
{
    return (9.0 / 5.0) * cel + 32;
}

float kel2cel(float kel)
{
    return kel - 273;
}

float kel2fah(float kel)
{
    return (9.0 / 5.0) * kel2cel(kel) + 32;
}

float fah2cel(float fah)
{
    return fah / (9.0 / 5.0) - 32;
}

float fah2kel(float fah)
{
    return fah2cel(fah) + 273;
}