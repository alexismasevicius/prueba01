#include <stdio.h>
#include <stdlib.h>


int sumar (int operador1,int operador2)
{
    int resultado;

    resultado = operador1 + operador2;

    return resultado;
}

int restar (int operador1,int operador2)
{
    int resultado;

    resultado = operador1 - operador2;

    return resultado;
}

int multiplicar (int operador1,int operador2)
{
    int resultado;

    resultado = operador1 * operador2;

    return resultado;
}

float dividir (int operador1,int operador2)
{
    float resultado;

    if(operador2==0)
    {
        resultado=0;
    }
    else
    {
        resultado=(float)operador1/operador2;
    }

    return resultado;
}

