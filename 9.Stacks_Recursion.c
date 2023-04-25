// Write a program to calculate the factorial of a given number.

#include <stdio.h>

int Fact(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * Fact(n - 1));
}

int main()
{
    int num, val;
    printf("\n Enter the number: ");
    scanf("%d", &num);
    val = Fact(num);
    printf("\n Factorial of %d = %d", num, val);
    return 0;
}

// Write a program to calculate the GCD of two numbers using recursive functions.

#include <stdio.h>

int GCD(int x, int y)
{
    int rem;
    rem = x % y;
    if (rem == 0)
        return y;
    else
        return (GCD(y, rem));
}

int main()
{
    int num1, num2, res;
    printf("\n Enter the two numbers: ");
    scanf("%d %d", &num1, &num2);
    res = GCD(num1, num2);
    printf("\n GCD of %d and %d = %d", num1, num2, res);
    return 0;
}

// Write a program to calculate exp(x,y) using recursive functions.

#include <stdio.h>
int exp_rec(int x, int y)
{
    if (y == 0)
        return 1;
    else
        return (x * exp_rec(x, y - 1));
}

int main()
{
    int num1, num2, res;
    printf("\n Enter the two numbers: ");
    scanf("%d %d", &num1, &num2);
    res = exp_rec(num1, num2);
    printf("\n RESULT = %d", res);
    return 0;
}

// Write a program to print the Fibonacci series using recursion.

#include <stdio.h>
int Fibonacci(int);
int main()
{
    int n, i = 0, res;
    printf("Enter the number of terms\n");
    scanf("%d", &n);
    printf("Fibonacci series\n");
    for (i = 0; i < n; i++)
    {
        res = Fibonacci(i);
        printf("%d\t", res);
    }
    return 0;
}
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
}