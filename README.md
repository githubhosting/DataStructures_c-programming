# DATA STRUCTURE PROGRAMS IN C PROGRAMMING

## This repository contains all the programs of data structure in c programming language

---

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

<details><summary><b>Infix Expression to Postfix Expression</b></summary>

```c
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
```

</details>

<details><summary><b>Infix Expression to Prefix Expression</b></summary>

```c
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
    if (x == '^')
        return 3;
    return 0;
}

void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (exp[i] != '\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp, temp);
}

void brackets(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    reverse(exp);
    brackets(exp);
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
            while (priority(stack[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c ", pop());
    }
    printf("\n");
    return 0;
}
```

</details>

<details><summary><b>Postfix Evaluation</b></summary>

```c
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1, n2, n3, num;
    printf("Enter the expression :: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48; // converting char to int
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*e)
            {
            case '+':
            {
                n3 = n2 + n1;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n2 * n3;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n", exp, pop());
    return 0;
}
```

</details>

<details><summary><b>Parentheses Checker</b></summary>

```c
#include <stdio.h>
#include <string.h>
#define MAX 10
int top = -1;
int stk[MAX];
void push(char);
char pop();
void main()
{
    char exp[MAX], temp;
    int i, flag = 1;
    printf("Enter an expression : ");
    gets(exp);
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            if (top == -1)
                flag = 0;
            else
            {
                temp = pop();
                if (exp[i] == ')' && (temp == '{' || temp == '['))
                    flag = 0;
                if (exp[i] == '}' && (temp == '(' || temp == '['))
                    flag = 0;
                if (exp[i] == ']' && (temp == '(' || temp == '{'))
                    flag = 0;
            }
    }
    if (top >= 0)
        flag = 0;
    if (flag == 1)
        printf("\n Valid expression");
    else
        printf("\n Invalid expression");
}
void push(char c)
{
    if (top == (MAX - 1))
        printf("Stack Overflow\n");
    else
    {
        top = top + 1;
        stk[top] = c;
    }
}
char pop()
{
    if (top == -1)
        printf("\n Stack Underflow");
    else
        return (stk[top--]);
}
```

</details>

<details><summary><b>Queue using Array</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow ");
    else
    {
        if (front == -1) //If queue is initially empty
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
```

</details>

---

## Credits to [Reema Thareja Book](https://drive.google.com/file/d/1wtduI3P1X3EmPdMr3eVm8VRAkRq83NUX/view?usp=share_link)
