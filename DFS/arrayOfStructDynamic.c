#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[30];
    unsigned int id;
    int salary;
};

struct Employee findHighestSalaryEmployee(struct Employee*, int);

int main() 
 {
  
    printf("\n----------------------------------------------------------\n");

    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);


    struct Employee* employees = (struct Employee*) calloc(numEmployees, sizeof(struct Employee));


        for (int i = 0; i <numEmployees; i++) 
         {
            printf("\nEnter employee #%d data:\n", i+1);
    
            printf("Enter name: ");
            scanf("%s", employees[i].name);
    
            printf("Enter ID: ");
            scanf("%u", &employees[i].id);
    
            printf("Enter salary: ");
            scanf("%d", &employees[i].salary);
         }

    struct Employee highestSalaryEmployee = findHighestSalaryEmployee(employees, numEmployees);

    printf("The employee with the highest salary is %s (ID: %u) with a salary of %d.\n",
           highestSalaryEmployee.name, highestSalaryEmployee.id, highestSalaryEmployee.salary);

    free(employees);
   
    printf("\n----------------------------------------------------------\n");
    return 0;
 }

struct Employee findHighestSalaryEmployee(struct Employee* employees, int numEmployees) 
 {
    int highestSalary = employees[0].salary;
    int highestSalaryIndex = 0;

    for (int i = 1; i < numEmployees; i++) 
     {
        if (employees[i].salary > highestSalary) 
         {
            highestSalary = employees[i].salary;
            highestSalaryIndex = i;
         }
     }

    return employees[highestSalaryIndex];
 }
