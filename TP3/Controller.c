#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;


    if(ll_isEmpty(pArrayListEmployee)==0)
    {
        pArrayListEmployee = ll_newLinkedList();

        pFile = fopen(path, "r");

        parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("Ya hay una lista cargada.");
    }



    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    //ALTA EMPLEADO
    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

void menu ()
{
    printf("*******************************\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados \n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n.");
    printf("10-Salir\n");
    printf("*******************************\n");
    printf("Ingrese una opcion:\n");

}
