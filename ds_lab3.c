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

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Push ");
        printf("\n2.Pop ");
        printf("\n3.Display ");
        printf("\n4.Quit ");
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
        default:
            printf("Wrong choice ");
        }
    }
} /*End of main()*/
