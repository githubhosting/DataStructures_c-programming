// Define an EMPLOYEE structure with members Emp_name, Emp-id,
// Dept-name and Salary. Read and display data of N employees.

// Employees may belong to different departments. Write a function
// to find the total salary of employees of a specified department.
// Use the concept of pointer to structure and allocate the memory
// dynamically to EMPLOYEE instances.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAMELEN 50
#define MAX_DEPTLEN 50

typedef struct employee
{
    char Emp_name[MAX_NAMELEN];
    int Emp_id;
    char Dept_name[MAX_DEPTLEN];
    float Salary;
} EMPLOYEE;

float total_salary_by_dept(EMPLOYEE *emp_array, int n, char *dept_name);

int main()
{
    int n, i;
    char dept_name[MAX_DEPTLEN];
    EMPLOYEE *emp_array;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    emp_array = (EMPLOYEE *)malloc(n * sizeof(EMPLOYEE));

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", emp_array[i].Emp_name);
        printf("Enter the id of employee %d: ", i + 1);
        scanf("%d", &emp_array[i].Emp_id);
        printf("Enter the department of employee %d: ", i + 1);
        scanf("%s", emp_array[i].Dept_name);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%f", &emp_array[i].Salary);
    }

    printf("Enter the department name: ");
    scanf("%s", dept_name);
    float total_salary = total_salary_by_dept(emp_array, n, dept_name);

    printf("Total salary of employees in %s department is %.2f", dept_name, total_salary);
    free(emp_array);

    return 0;
}

float total_salary_by_dept(EMPLOYEE *emp_array, int n, char *dept_name)
{
    float total_salary = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(emp_array[i].Dept_name, dept_name) == 0)
        {
            total_salary += emp_array[i].Salary;
        }
    }
    return total_salary;
}