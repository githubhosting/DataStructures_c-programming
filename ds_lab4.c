// Enter the infix expression to convert to postfix expression
// Write a C program to convert and print a given valid parenthesized
// infix arithmetic expression to postfix expression. The expression
// consists of single-character operands and binary operators + - * /.
// Apply the concept of stack data structure to solve this problem.

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp; // e is a pointer to expression

    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c ", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(') // pop until ( is encountered
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e)) // pop until priority of stack top is less than that of *e
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c ", pop()); // pop until stack is empty
    }
    return 0;
}
