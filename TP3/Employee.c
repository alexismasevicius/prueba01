#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* miEmpleado;

    return miEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* miEmpleado;

    miEmpleado = (Employee*) malloc (sizeof(Employee));
    if(employee_setId(miEmpleado,atoi(idStr))==1)
    {
        employee_setId(miEmpleado,atoi(idStr));
    }
    if(employee_setNombre(miEmpleado,nombreStr)==1)
    {
        employee_setNombre(miEmpleado,nombreStr);
    }
    if(employee_setHorasTrabajadas(miEmpleado,atoi(horasTrabajadasStr))==1)
    {
        employee_setHorasTrabajadas(miEmpleado,atoi(horasTrabajadasStr));
    }
    if(employee_setSueldo(miEmpleado,atoi(sueldoStr))==1)
    {
        employee_setSueldo(miEmpleado,atoi(sueldoStr));
    }
    return miEmpleado;

}



int employee_setId(Employee* this,int id)
{
    if(this!=NULL)
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
    *id = this->id; //validar nulo y devolver 1 o 0 si se pudo
    //USAR EN FUNCION QUE MUESTRA UN EMPLEADO
    return 0;
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

