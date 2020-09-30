
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
void ShowEmployeeById (Employee list[],int len);
void hardCodeList(Employee list[]);






