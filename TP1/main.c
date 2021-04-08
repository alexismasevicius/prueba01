#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "funciones.h"
#include "utn.h"


int main()
{
    //int primerOperando;
    //int segundoOperando;
    int seleccionador;


    utn_getNumero(&seleccionador,"Ingrese una opcion: \n","Error.\n",1,5,10);
    printf("%d", seleccionador);

    switch(seleccionador)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:



            break;
    }



    return 0;
}
