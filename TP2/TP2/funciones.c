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
    printf("10-SALIR \n");
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
    printf("1-MOSTRAR LISTA\n");
    printf("2-ORDENAR POR APELLIDO Y SECTOR\n");
    printf("3-INFORMAR TOTAL, PROMEDIO DE SALARIOS Y CUANTOS SUPERAN EL SALARIO PROMEDIO\n");
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

    emptySpace=-1;

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

    i=SearchEmptySpace(list, len); //busca espacio libre en memoria
    emptySpace=i+1;                 //agrego 1 para mostrar

    if(emptySpace!=0)
    {
        counterEmptySpaces=len-i;
        printf("\nEl espacio %d se encuentra vacio.",emptySpace);
        printf("\nLe quedan %d espacios vacios para cargar.\n",counterEmptySpaces);
        list[i] = CreateEmployee();
        list[i].id = i+1;
    }
    else
    {
        printf("\nNo quedan mas lugares para cargar.\n");
    }

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
void PrintEmployees (Employee list[],int len)
{
    int i;

    printf("\n--------------------------------------------------------------\n");
    printf("\nLos empleados son:\n");

    printf("%-5s %-20s %-20s %20s %5s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            printf("%-5d %-20s %-20s %20f %5d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }

    printf("\n--------------------------------------------------------------\n");

}

///ORDENAR LISTA POR APELLIDO

void SortEmployeeByName (Employee list[], int len, int order)
{
    int i;
    int j;
    Employee auxEmployee;

    if(order==1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                   auxEmployee = list[i];
                   list[i] = list[j];
                   list[j] = auxEmployee;
                }
                if(list[i].sector>list[j].sector)
                {
                   auxEmployee = list[i];
                   list[i] = list[j];
                   list[j] = auxEmployee;
                }
            }
        }
    }
    else
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                   auxEmployee = list[i];
                   list[i] = list[j];
                   list[j] = auxEmployee;
                }
                if(list[i].sector<list[j].sector)
                {
                   auxEmployee = list[i];
                   list[i] = list[j];
                   list[j] = auxEmployee;
                }
            }
        }
    }

}

///CALCULAR PROMEDIO

float AverageCalculator (Employee list[], int len)
{
    int i;
    float acc;
    int counter;
    float ans;

    acc=0;
    counter=0;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            counter++;
            acc=acc+list[i].salary;
        }
    }
    ans=acc/counter;

    return ans;
}

///CALCULAR TOTAL
float TotalCalculator (Employee list[], int len)
{
    int i;
    float acc;

    acc=0;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            acc=acc+list[i].salary;
        }
    }

    return acc;
}


///MOSTRAR EMPLEADOS QUE SUPERAN EL PROMEDIO

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
