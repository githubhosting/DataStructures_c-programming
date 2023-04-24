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
