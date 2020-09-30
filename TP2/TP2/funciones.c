#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

///MENU INICIAL
void MenuInicial()
{

    printf("*******************************\n");
    printf("1-ALTAS\n");
    printf("2-MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    printf("5-HERRAMIENTAS\n");
    printf("10-Salir \n");
    printf("*******************************\n");

}

///MENU AGREGAR
void MenuAdd()
{
    printf("*******************************\n");
    printf("1-ALTA EMPLEADO NUEVO\n");
    printf("*******************************\n");
}

///MENU MODIFICAR
void MenuModify()
{
    printf("*******************************\n");
    printf("1-MODIFICAR UN EMPLEADO\n");
    printf("*******************************\n");
}

///MENU BORRAR
void MenuDelete()
{
    printf("*******************************\n");
    printf("1-BORRAR UN EMPLEADO\n");
    printf("*******************************\n");
}

///MENU INFORMAR
void MenuInform()
{
    printf("*******************************\n");
    printf("1-MOSTRAR LISTA ORDENADA POR ID\n");
    printf("*******************************\n");
}

///MENU HERRAMIENTAS

void MenuTools()
{
    printf("*******************************\n");
    printf("1-HARDCODEAR LISTA\n");
    printf("*******************************\n");
}

///******************************************************************************************************************************************

///INICIALIZAR
void InitEmployees(Employee list[], int len)
{
    int i;
    Employee initList;

    for(i=0;i<len;i++)
    {
       initList.isEmpty=0;
       list[i]=initList;
    }
}

///BUSCAR ESPACIO VACIO
int SearchEmptySpace (Employee list[], int len)
{
    int emptySpace;
    int i;

    emptySpace=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            emptySpace=i;
            break;
        }
    }
    return emptySpace;
}

///ENCONTRAR EMPLEADO
int FindEmployeeById (Employee list[], int len,int idIn)
{
    int i;
    int ans;
    Employee test;

    test.id=idIn;

    for(i=0;i<len;i++)
        {
           if(list[i].id==test.id)
           {
               ans=i;
           }
        }
    return ans;
}

///******************************************************************************************************************************************


///CREAR EMPLEADO
Employee CreateEmployee ()
{
    Employee newEmployee;

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", newEmployee.name);

    printf("Ingrese apellido: ");
    fflush(stdin);
    scanf("%[^\n]", newEmployee.lastName);

    printf("Ingrese salario: ");
    scanf("%f",&newEmployee.salary);

    printf("Ingrese sector: ");
    scanf("%d",&newEmployee.sector);

    newEmployee.isEmpty=1;

    return newEmployee;
}

///CARGAR EMPLEADO
void AddEmployee(Employee list[], int len)
{
    int i;
    int emptySpace;
    int counterEmptySpaces;

    i=SearchEmptySpace(list, len);
    emptySpace=i+1;
    counterEmptySpaces=len-i;
    printf("\nEl espacio %d se encuentra vacio.",emptySpace);
    printf("\nLe quedan %d espacios vacios para cargar.\n",counterEmptySpaces);
    list[i] = CreateEmployee();
    list[i].id = i+1;

}

///******************************************************************************************************************************************


///MODIFICAR EMPLEADO
void ModifyEmployee (Employee list[],int len)
{
    int ansOne;
    int ansTwo;
    Employee newEmployee;
    int i;

    printf("\n Ingrese el numero de ID del empleado que desea modificar: ");
    scanf("%d", &ansOne);
    i=FindEmployeeById(list,len,ansOne);

    printf("\n Ingrese el aspecto que desea modificar que desea modificar: \n");
    printf("\n*******************************\n");
    printf("1-NOMBRE\n");
    printf("2-APELLIDO\n");
    printf("3-SALARIO\n");
    printf("4-SECTOR\n");
    printf("*******************************\n");
    scanf("%d", &ansTwo);

    switch(ansTwo)
    {
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%[^\n]", newEmployee.name);
            strcpy(list[i].name, newEmployee.name);
            break;
        case 2:
            printf("Ingrese apellido: ");
            fflush(stdin);
            scanf("%[^\n]", newEmployee.lastName);
            strcpy(list[i].lastName, newEmployee.lastName);
            break;
        case 3:
            printf("Ingrese salario: ");
            scanf("%f", &newEmployee.salary);
            newEmployee.salary=list[i].salary;
            break;
        case 4:
            printf("Ingrese sector: ");
            scanf("%d", &newEmployee.sector);
            newEmployee.sector=list[i].sector;
            break;
        default:
            printf("Error. Ingresa un numero del 1 al 4");
            scanf("%d", &ansTwo);
            break;
    }

}

///******************************************************************************************************************************************

///BORRAR EMPLEADO
void DeleteEmployee (Employee list[],int len)
{
    int ansOne;
    int i;

    printf("\n Ingrese el numero de ID del empleado que desea borrar: ");
    scanf("%d", &ansOne);
    i=FindEmployeeById(list,len,ansOne);

    list[i].isEmpty=0;
}


///******************************************************************************************************************************************

///MOSTRAR LISTA POR ID
void ShowEmployeeById (Employee list[],int len)
{
    int i;

    printf("\nLos empleados ordenados por ID son:\n");

    printf("%s %8s %8s %20s %20s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(i=0;i<len;i++)
    {
        printf("%d %8s %8s %20f %20d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
    }

}

///******************************************************************************************************************************************

///HARCODEAR EMPLEADOS

void hardCodeList(Employee list[])
{
    int idArray[6]={1,2,3,4,5,6};
    char nameArray[6][51]={"pedro","juan","mateo","cesar","julio","matias"};
    char lastNameArray[6][51]={"lopez","rodriguez","garcia","ramirez","cruz","gonzalez"};
    int isEmptyArray[6]={1,1,1,1,1,1};
    float salarayArray[6]={10,20,30,40,50,60};
    int sectorArray[6]={1,2,1,2,1,2};

    int i;

    for(i=0;i<6;i++)
    {
        list[i].id=idArray[i];
        strcpy(list[i].name, nameArray[i]);
        strcpy(list[i].lastName, lastNameArray[i]);
        list[i].isEmpty=isEmptyArray[i];
        list[i].salary=salarayArray[i];
        list[i].sector=sectorArray[i];
    }
}
