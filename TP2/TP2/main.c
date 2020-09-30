#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMANIO 6

int main()
{
    Employee listOfEmployees[TAMANIO];
    int opcion;
    int flagFirstAdd;

    flagFirstAdd=0;

    ///INICIALIZA ARRAY
    InitEmployees(listOfEmployees, TAMANIO);

    ///TODOS LOS MENUS
    do
    {
        printf("\n");
        MenuInicial();
        scanf("%d", &opcion);
        switch(opcion)
        {
            ///MENU AGREGAR
            case 1:
                printf("\n");
                MenuAdd();
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                        if(flagFirstAdd==0)
                        {
                            flagFirstAdd=1;
                            AddEmployee(listOfEmployees, TAMANIO);
                        }
                        else
                        {
                            AddEmployee(listOfEmployees, TAMANIO);
                        }
                        break;
                    default:
                        printf("\nNo ha seleccionado una opcion valida.\n");
                }
            break;

            ///MENU MODIFICAR
            case 2:
                printf("\n");
                if(flagFirstAdd==0)
                {
                    printf("Debe cargar algun empleado primero.\n");
                    break;
                }
                else
                {
                    MenuModify();
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            ModifyEmployee (listOfEmployees, TAMANIO);
                        break;
                        default:
                            printf("\nNo ha seleccionado una opcion valida.\n");

                    }
                    break;
                }

            ///MENU BORRAR
            case 3:
                printf("\n");
                if(flagFirstAdd==0)
                {
                    printf("Debe cargar algun empleado primero.\n");
                    break;
                }
                else
                {
                    MenuDelete();
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            ModifyEmployee (listOfEmployees, TAMANIO);
                            break;
                        default:
                            printf("\nNo ha seleccionado una opcion valida.\n");
                    }
                    break;

                }

            ///MENU INFORMAR
            case 4:
                printf("\n");
                if(flagFirstAdd==0)
                {
                    printf("Debe cargar algun empleado primero.\n");
                    break;
                }
                else
                {
                    MenuInform();
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            ShowEmployeeById (listOfEmployees, TAMANIO);
                            break;
                        default:
                            printf("\nNo ha seleccionado una opcion valida.\n");

                    }

                    break;
                }

            ///MENU HERRAMIENTAS
            case 5:
                printf("\n");
                MenuTools();
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                        hardCodeList(listOfEmployees);
                        flagFirstAdd=1;
                        break;
                    default:
                        printf("\nNo ha seleccionado una opcion valida.\n");
                }
                break;

            default:
                    printf("\nNo ha seleccionado una opcion valida.\n");

        } //FIN DEL SWITCH
    }while(opcion!=10);

    return 0;

}
