#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int main()
{
    LinkedList* miLista;

    miLista = ll_newLinkedList();

    int respuesta;
    do
    {
    menu();
    scanf("%d", &respuesta);
    switch(respuesta)
    {
        case 1:
            controller_loadFromText("data.csv", miLista);
        break;
        case 2:

        break;
        case 3:
            controller_addEmployee(miLista);
        break;
        case 4:
            controller_editEmployee(miLista);
        break;
        case 5:
            controller_removeEmployee(miLista);
        break;
        case 6:
            controller_ListEmployee(miLista);
        break;
        case 7:

        break;
        case 8:

        break;
        case 9:

        break;

    }

   }while(respuesta!=10);




   /* LinkedList* miLista;

    miLista = ll_newLinkedList();

    int len;
    int i;
    len = ll_len(miLista);

    printf("Cantidad de elementos : %d\n", len);

    Employee* e1;
    e1 = (Employee*) malloc(sizeof(Employee));

    e1->id = 100;
    e1->horasTrabajadas = 10;
    e1->sueldo = 50000;
    strcpy(e1->nombre, "Juan");

    mostrarEmpleado(e1);

    ll_add(miLista,e1);

    len = ll_len(miLista);

    printf("Cantidad de elementos : %d\n", len);

    Employee* e2;
    e2 = (Employee*) malloc(sizeof(Employee));

    e2->id = 1000;
    e2->horasTrabajadas = 20;
    e2->sueldo = 40200;
    strcpy(e2->nombre, "ALBERT");


    mostrarEmpleado(e2);
    ll_add(miLista,e2);

    len = ll_len(miLista);

    printf("Cantidad de elementos : %d\n", len);

--------------------------------------------
    //AGREGAR
    Employee* aux;

    printf("Lista de empleados: \n");
    for(i=0; i<len ; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d-", i+1);
        mostrarEmpleado(aux);
    }


   //----------------------------------------
    //SET
    int index = 2;
    Employee* e5;
    index = 2;
    e5 = (Employee*) malloc(sizeof(Employee));

    e5->id = 350;
    e5->horasTrabajadas = 5;
    e5->sueldo = 100023;
    strcpy(e5->nombre,"Ramon");

    ll_set(miLista, index-1, e5);

        printf("Lista de empleados con segundo modificado: \n");
    for(i=0; i<len ; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d-", i+1);
        mostrarEmpleado(aux);
    }
    //---------------------------------------
    ll_push(miLista,1,e1);
    printf("Lista de empleados con ---- pusheado: \n");
    len = ll_len(miLista);

    for(i=0; i<len ; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d-", i+1);
        mostrarEmpleado(aux);
    }

    //--------------------------------------
    //BORRAR

    printf("sacamos un Empleado : \n");

    ll_remove(miLista, index-1);

    printf("Lista de empleados con el segundo eliminado: \n");
    len = ll_len(miLista);

    for(i=0; i<len ; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d-", i+1);
        mostrarEmpleado(aux);
    }

*/
    return 0;
}

/*void mostrarEmpleado(Employee* unEmpleado)
{
    printf("%4d %15s %8d %4d\n", unEmpleado->id,
                                unEmpleado->nombre,
                                unEmpleado->horasTrabajadas,
                                unEmpleado->sueldo);

}*/
