// Circular Queue implementation using structure in C Programming

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct queue
{
    int data[MAX];
    int front;
    int rear;
};
void insert(struct queue *q, int val)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = q->rear + 1;
        q->data[q->rear] = val;
    }
}
void delete(struct queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = q->front + 1;
        printf("Deleted element is %d \n", q->data[q->front]);
    }
}
void display(struct queue *q)
{
    int i;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d \t", q->data[i]);
        }
        printf("\n");
    }
}
void main()
{
    struct queue q;
    int ch, val;
    q.front = -1;
    q.rear = -1;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insert(&q, val);
            break;
        case 2:
            delete (&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}