// Queue in Data Structure | Queue implementation using array in c

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow ");
    else
    {
        if (front == -1) // If queue is initially empty
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue[rear] = add_item;
    }
}

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
}

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
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
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
}
