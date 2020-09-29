#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMANIO 6

int main()
{
    Employee listOfEmployees[TAMANIO];
    int opcion;

    ///inicializar array
    InitEmployees(listOfEmployees, TAMANIO);

    ///menu
    do
    {
        printf("\n");
        MenuInicial();
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\n");
                MenuAdd();
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                        AddEmployee(listOfEmployees, TAMANIO);
                        break;
                }
            break;
            case 2:
                printf("\n");
                MenuModify();
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                        ModifyEmployee (listOfEmployees);
                        break;
                }
            break;
        }

    }while(opcion!=10);

    return 0;

}
