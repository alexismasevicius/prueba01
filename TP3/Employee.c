#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    Employee* miEmpleado;
    char auxNom[50];
    char auxId[50];
    char auxHoras[50];
    int auxHorasInt;
    char auxSueldo[50];
    int auxSueldoInt;

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", auxNom);
    while(esSoloLetras(auxNom)==0 || strlen(auxNom)>20)
    {
        printf("Error. Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", auxNom);
    }

    printf("Ingrese horas trabajadas: ");
    fflush(stdin);
    gets(auxHoras);
    auxHorasInt=atoi(auxHoras);
    while(esNumerico(auxHoras)==0 || auxHorasInt<0 || auxHorasInt>100000)
    {
        printf("Error. Ingrese horas trabajadas: ");
        fflush(stdin);
        gets(auxHoras);
        auxHorasInt=atoi(auxHoras);
    }

    printf("Ingrese sueldo: ");
    fflush(stdin);
    gets(auxSueldo);
    auxSueldoInt=atoi(auxSueldo);
    while(esNumerico(auxSueldo)==0 || auxSueldoInt<0 || auxSueldoInt>100000)
    {
        printf("Error. Ingrese sueldo: ");
        fflush(stdin);
        gets(auxSueldo);
        auxSueldoInt=atoi(auxSueldo);
    }

    strcpy(auxId,"error");
    miEmpleado=employee_newParametros(auxId,auxNom,auxHoras,auxSueldo);


    return miEmpleado;

}

int employee_NewId(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;
    int auxId;
    len=ll_len(pArrayListEmployee);

    if(len>0)
    {
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(aux,&auxId);
            if(auxId!=i+1)
            {
                auxId=auxId-1;
                break;
            }
            else
            {
                auxId=len+1;
            }
        }
    }
    else
    {
        auxId=1;
    }
    printf("\n%d\n", auxId);
    return auxId;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* miEmpleado;
    int auxInt;
    int auxNom;
    int auxHoras;
    int auxSueldo;

    miEmpleado = (Employee*) malloc (sizeof(Employee));

    auxInt=employee_setId(miEmpleado,atoi(idStr));
    auxNom=employee_setNombre(miEmpleado,nombreStr);
    auxHoras=employee_setHorasTrabajadas(miEmpleado,atoi(horasTrabajadasStr));
    auxSueldo=employee_setSueldo(miEmpleado,atoi(sueldoStr));

    if(auxInt==1 && auxNom==1 && auxHoras==1 && auxSueldo==1)
    {
        employee_setId(miEmpleado,atoi(idStr));
        employee_setNombre(miEmpleado,nombreStr);
        employee_setHorasTrabajadas(miEmpleado,atoi(horasTrabajadasStr));
        employee_setSueldo(miEmpleado,atoi(sueldoStr));
    }

    return miEmpleado;

}

int employee_list(LinkedList* pArrayListEmployee, int len)
{
    int i;
    Employee* aux;
    int id;
    int horas;
    char nombre[50];
    int sueldo;
    int auxInt;
    int auxNom;
    int auxHoras;
    int auxSueldo;

    for(i=0; i<len; i++)
   {
        aux=(Employee*)ll_get(pArrayListEmployee, i);
        auxInt=employee_getId(aux, &id);
        auxNom=employee_getNombre(aux, nombre);
        auxHoras=employee_getHorasTrabajadas(aux, &horas);
        auxSueldo=employee_getSueldo(aux,&sueldo);

        if(auxInt==1 && auxNom==1 && auxHoras==1 && auxSueldo==1)
        {        employee_getId(aux, &id);
            employee_getNombre(aux, nombre);
            employee_getHorasTrabajadas(aux, &horas);
            employee_getSueldo(aux,&sueldo);
            printf("%4d |%15s |%8d | %4d\n",id,nombre,horas,sueldo);
        }
        else
        {
            printf("No se encontro.\n");
        }
    }

    return 0;
}


int employee_setId(Employee* this,int id)
{
    if(id>0 && this!=NULL)
    {
        this -> id = id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getId(Employee* this,int* id)
{
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL)
    {
        this -> horasTrabajadas = horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }

}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL)
    {
        this -> sueldo = sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre,e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int comp = 0;

    if(e1->id > e2->id)
    {
        comp = 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            comp=-1;
        }
    }

    return comp;

}

