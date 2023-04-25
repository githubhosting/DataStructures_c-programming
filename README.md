# DATA STRUCTURE PROGRAMS IN C PROGRAMMING

## This repository contains all the programs of data structure in c programming language

### List of programs

1. [Dynamic Memory Allocation](#dynamic-memory-allocation)
2. [Array Operations](#array-operations)

Dynamic Memory Allocation

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

Array Operations

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
