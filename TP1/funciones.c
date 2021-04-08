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



/** \brief realiza una division entre dos enteros.
 *
 * \param 1: operador1 dividendo.
 * \param 2: operador2 divisor.
 * \param 3: operadorSalida Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \return Retorna  1 si es exitosa, 0 si es ERROR
 *
 */
float dividir (int operador1, int operador2, float* operadorSalida)
{
    int todoOk = 0;

    if(operador2!=0 && operadorSalida!=NULL)
    {
        *operadorSalida=(float)operador1/operador2;
        todoOk=1;
    }
    return todoOk;
}

int factorizar (int operador)
{
    int resultado;

    if(operador==0)
    {
        resultado=1;
    }
    else
    {
        resultado=operador*factorizar(operador-1);
    }
    return resultado;
}

