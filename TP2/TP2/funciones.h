
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void MenuInicial();
void MenuAdd();
void MenuModify();
void MenuDelete();
void MenuInform();
void MenuTools();
void InitEmployees(Employee list[], int len);
int SearchEmptySpace (Employee list[], int len);
int FindEmployeeById (Employee list[], int len,int idIn);
Employee CreateEmployee ();
void AddEmployee(Employee list[], int len);
void ModifyEmployee (Employee list[],int len);
void DeleteEmployee (Employee list[],int len);
void PrintEmployees (Employee list[],int len);
void SortEmployeeByName (Employee list[], int len, int order);
float AverageCalculator (Employee list[], int len);
float TotalCalculator (Employee list[], int len);
void hardCodeList(Employee list[]);






