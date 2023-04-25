# DATA STRUCTURE PROGRAMS IN C PROGRAMMING

## This repository contains all the programs of data structure in c programming language

## List of programs

<details><summary><b>Dynamic Memory Allocation</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // This pointer will hold the
    // base address of the block created
    int *ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    // Since the size of int is 4 bytes, this statement will allocate n*4 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.
    ptr = (int *)malloc(n * sizeof(int));

    // Dynamically allocate memory using calloc()
    // This statement allocates contiguous space in memory for n elements each with the size of the float.
    ptr = (float *)calloc(n, sizeof(float));

    // Dynamically re-allocate memory using realloc()
    ptr = realloc(ptr, n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc/calloc or not
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i)
        {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d, ", ptr[i]);
        }

        // Free the memory
        free(ptr);
        printf("Malloc Memory successfully freed.\n");
    }

    return 0;
}
```

</details>

<details><summary><b>Array Operations</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int arr[MAX];
int pos, elem, n;

void create();
void display();
void insert();
void delete();

void create()
{
    int i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display()
{
    int i;
    if (n == 0)
    {
        printf("Array is empty ");
        return;
    }
    printf("Array elements are : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf(" ");
}

void insert()
{
    int i;
    if (n == MAX)
    {
        printf("Array is full ");
        return;
    }
    printf("Enter the position for the new element : ");
    scanf("%d", &pos);
    printf("Enter the element to be inserted : ");
    scanf("%d", &elem);
    for (i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];
    arr[pos] = elem;
    n = n + 1;
}

void delete()
{
    int i;
    printf("Enter the position of the element to be deleted : ");
    scanf("%d", &pos);
    elem = arr[pos];
    printf("Element deleted is : %d ", elem);
    for (i = pos; i <= n - 1; i++)
        arr[i] = arr[i + 1];
    n = n - 1;
}

int main()
{
    int choice;
    int pos = 1;
    while (1)
    {
        printf("\n1.Create an array ");
        printf("\n2.Display the array ");
        printf("\n3.Insert an element ");
        printf("\n4.Delete an element ");
        printf("\n5.Exit ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice ");
        }
    }
}
```

</details>

<details><summary><b>Stacks Array</b></summary>

```c
// Write a c program to implement STACK using array
// STACK of Integers (Array Implementation of Stack with maximum
// size MAX)
// a) Push an Element on to Stack
// b) Pop an Element from Stack
// c) Demonstrate how Stack can be used to check Palindrome
// d) Demonstrate Overflow and Underflow situations on Stack
// e) Display the status of Stack
// f) Exit
// Support the program with appropriate functions for each of the
// above operations

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
        printf("Stack Overflow ");
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

int pop()
{
    int x;
    if (top == -1)
        printf("Stack Underflow ");
    else
    {
        x = stack[top];
        top = top - 1;
        return x;
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("Stack is empty ");
    else
    {
        printf("Stack elements are : ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
}

void check_palindrome()
{
    int i, j, flag = 0;
    char str[20];
    printf("Enter the string : ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
        push(str[i]);
    for (j = 0; str[j] != '\0'; j++)
    {
        if (str[j] != pop()) // str[j] is first element of string and pop() is last element of string
        {
            flag = 1; // if first and last elements are not same then flag is set to 1
            break;
        }
    }
    if (flag == 1)
        printf("String is not a palindrome ");
    else
        printf("String is a palindrome ");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Push ");
        printf("\n2.Pop ");
        printf("\n3.Display ");
        printf("\n4.Quit ");
        printf("\n5.Check Palindrome ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("Popped element is : %d", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        case 5:
            check_palindrome();
            break;
        default:
            printf("Wrong choice ");
        }
    }
}
```

</details>
