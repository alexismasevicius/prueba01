#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int i;
    int cont;
    int len;
    char id[50];
    char nombre[50];
    char horas[50];
    char sueldo[50];
    Employee* miEmpleado;
    Employee* aux;



    i=0;

    cont = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);
    while(!feof(pFile))
    {
        cont = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);

        if(cont==4)
        {
            miEmpleado=employee_newParametros(id,nombre,horas,sueldo);

            ll_add(pArrayListEmployee, miEmpleado);


            i++;
        }

    }
    fclose(pFile);

    len = ll_len(pArrayListEmployee);

    for(i=0; i<len; i++)
   {
     aux=(Employee*)ll_get(pArrayListEmployee, i);
    printf("%4d |%15s |%8d | %4d\n", aux->id,
                                aux->nombre,
                                aux->horasTrabajadas,
                                aux->sueldo);
    }
        printf("cantidad de elementos: %d \n", len);

    return 1;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
