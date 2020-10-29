#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int controlador;

    controlador=ll_isEmpty(pArrayListEmployee);
    pFile = fopen(path, "r");

    if(controlador==1)
    {
        if(pFile!=NULL && pArrayListEmployee!=NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
        else
        {
            printf("Error.\n");
        }
    }
    else
    {
        printf("\nYa hay una lista cargada\n\n");
    }



    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* miEmpleado;
    int auxId;
    int index;


    miEmpleado=employee_new();

    if(miEmpleado!=NULL)
    {
        auxId=employee_NewId(pArrayListEmployee);
        employee_setId(miEmpleado,auxId);
        index=auxId-1;
        ll_push(pArrayListEmployee,index,miEmpleado);
        return 1;
    }
    else
    {
        return 0;
    }
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    Employee* miEmpleado;
    int controlador;

    controlador=ll_isEmpty(pArrayListEmployee);

    controller_ListEmployee(pArrayListEmployee);

    if(controlador==0)
    {
        printf("\nIngrese el numero de ID del empleado que desea modificar: \n");
        scanf("%d", &id);
        miEmpleado=employee_new();
        if(miEmpleado!=NULL)
        {
            employee_setId(miEmpleado,id);
            ll_set(pArrayListEmployee,id-1, miEmpleado);
            return 1;
        }
        else
        {
            printf("Error.\n");
            return 0;
        }
    }
    else
    {
        printf("Error.\n");
        return 0;
    }
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int controlador;

    if(pArrayListEmployee!=NULL)
    {
        controlador=ll_isEmpty(pArrayListEmployee);

        controller_ListEmployee(pArrayListEmployee);

        if(controlador==0)
        {
            printf("\nIngrese el numero de ID del empleado que desea borrar: \n");
            scanf("%d", &id);

            ll_remove(pArrayListEmployee,id-1);
            return 1;
        }
        else
        {
            printf("Error.\n");
            return 0;

        }
    }
    else
    {
        printf("Error.\n");
        return 0;
    }
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;


    if(pArrayListEmployee!=NULL)
    {
            len=ll_len(pArrayListEmployee);
            employee_list(pArrayListEmployee,len);
    }
    else
    {
        printf("Error!\n");
    }


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
