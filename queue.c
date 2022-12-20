// Queue in Data Structure | queue implementation using array in c

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert element to queue ");
        printf("\n2.Delete element from queue ");
        printf("\n3.Display all elements of queue ");
        printf("\n4.Quit ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice ");
        }
    }
} /*End of main()*/

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow ");
    else
    {
        if (front == -1) /*If queue is initially empty */
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue[rear] = add_item;
    }
} /*End of insert()*/

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow ");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d", queue[front]);
        front = front + 1;
    }
} /*End of delete() */

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty ");
    else
    {
        printf("Queue is : ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
} /*End of display() */
