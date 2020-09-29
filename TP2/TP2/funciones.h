
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
void InitEmployees(Employee list[], int len);
int SearchEmptySpace (Employee list[], int len);
Employee CreateEmployee ();
void AddEmployee(Employee list[], int len);
void ModifyEmployee (Employee list[]);




