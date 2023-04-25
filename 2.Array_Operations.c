// Design, Develop and Implement a menu driven Program in C for the
// following array operations.
// a) Creating an array of N Integer Elements
// b) Display of array Elements with Suitable Headings
// c) Inserting an Element (ELEM) at a given valid Position (POS)
// d) Deleting an Element at a given valid Position(POS)
// e) Exit.
// Support the program with functions for each of the above
// operations.

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