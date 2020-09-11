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
            printf("\nEl resultado de la suma entre %d y %d es: %d.\n",primerOperando,segundoOperando,resultadoInt);
            break;
        case 2:
            resultadoInt=restar(primerOperando,segundoOperando);
            printf("\nEl resultado de la resta entre %d y %d es: %d.\n",primerOperando,segundoOperando,resultadoInt);
            break;
        case 3:
            resultadoFloat=dividir(primerOperando,segundoOperando);
            if(resultadoFloat==0)
            {
                printf("\nNo es posible dividir por cero\n");
            }
            else
            {
                printf("\nEl resultado de la division entre %d y %d es: %f.\n",primerOperando,segundoOperando,resultadoFloat);
            }
            break;
        case 4:
            resultadoInt=multiplicar(primerOperando,segundoOperando);
            printf("\nEl resultado de la multiplicación entre %d y %d es: %d.\n",primerOperando,segundoOperando,resultadoInt);
            break;
        case 5:
            resultadoInt=factorizar(primerOperando);
            printf("\nEl factorial de %d es %d\n",primerOperando,resultadoInt);
            resultadoInt=factorizar(segundoOperando);
            printf("\nEl factorial de %d es %d\n",segundoOperando,resultadoInt);


            break;
    }



    return 0;
}
