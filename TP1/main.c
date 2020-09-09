#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"


int main()
{
    int primerOperando;
    int segundoOperando;
    int seleccionador;
    int resultadoInt;
    float resultadoFloat;

    printf("\nIngrese primer numero: ");
    scanf("%d", &primerOperando);

    printf("\nIngrese segundo numero: ");
    scanf("%d", &segundoOperando);

    printf("\nLos numeros ingresados fueron : %d y %d",primerOperando,segundoOperando);
    printf("\nPara calcular ingrese los siguientes numeros:\n-1 para sumar\n-2 para restar\n-3 para dividir\n-4 para multiplicar\n-5 para factorial\n");
    scanf("%d", &seleccionador);

    switch(seleccionador)
    {
        case 1:
            resultadoInt=sumar(primerOperando,segundoOperando);
            break;
        case 2:
            resultadoInt=restar(primerOperando,segundoOperando);
            break;
        case 3:
            resultadoFloat=dividir(primerOperando,segundoOperando);
            break;
        case 4:
            resultadoInt=multiplicar(primerOperando,segundoOperando);
            break;
       /* case 5:
            resultadoInt=factorizar(primerOperando,segundoOperando);
            break;*/
    }

    if(seleccionador!=3)
    {
        printf("\nEl resultado es: %d",resultadoInt);
        if(seleccionador==5)
        {

        }
    }
    else
    {
       printf("\nEl resultado es: %f", resultadoFloat);
    }


    return 0;
}
