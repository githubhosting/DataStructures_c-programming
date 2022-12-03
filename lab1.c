#include<stdio.h>
#define MAX 20
int arr[MAX];
int posn,element,size;

void create()
{
    int i;
    printf("Enter the elements of the array:\n");
    if(size == MAX)
    {
        size = MAX;    
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    else
    {
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
}
void display()
{
    int i;
    printf("Displaying the array:\n");
    for(i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void insertion()
{
    int i;
    size++;
    for(i=size;i>=posn;i--)    
    {
        arr[i] = arr[i-1];
    }
    arr[posn] = element;
}
void deletion(int pos)
{
    int i;
    size--;
    for(i=pos;i<size;i++)
    {
        arr[i] = arr[i+1];
    }
}
        
void main()
{
    int pos1;
    printf("Enter the size(less than 20) of the required array:\n");
    scanf("%d",&size);
    create();
    display();
    printf("Enter an element and the position(less than 20) where it should be inserted in the array:\n");
    scanf("%d%d",&element,&posn);
    insertion();
    display();
    printf("Enter the position from where the element should be deleted:\n");
    scanf("%d",&pos1);
}
    deletion(pos1);
    display();    
}    


Program 3
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int st[MAX];
int top=-1;
void push(int num);
void pop();
void palindrome(int pal);
void flow();
void status();
void main()
{
    int ch,n,pal,loop=1;
    while(loop == 1)
    {
        printf("Enter the suitable input for the following operations:\n"
            "1 to push an element onto the stack\n"
            "2 to pop an element from the stack\n"
            "3 to check for a palindrome number\n"
            "4 to check for overflow/underflow conditions\n"
            "5 to display the current status of stack\n"
            "6 to exit the program\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter a number to be pushed onto the stack\n");
                scanf("%d",&n);
                push(n);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                 printf("Enter a number to check whether it is a palindrome:\n");
                 scanf("%d",&pal);
                 palindrome(pal);
                 break;
             }
             case 4:
             {
                 flow();
                 break;
             }
             case 5:
             {
                 status();
                 break;
             }
             case 6:
             {
                 loop = 0;
                 break;
             }
             default:
             {
                 printf("Invalid choice");
             }
        }
    }
    
}
void push(int num)
{
     if( top == MAX - 1)
         printf("Stack Overflow!!\n");
    else
    {
        top += 1;
        st[top] = num;
    }
}
void pop()
{
    int val;
     if(top == -1)
         printf("Stack Underflow!!\n");
     else
     {
         val = st[top];
         top -= 1;
     }
     printf("The element popped is:%d\n",val);
     
}
void palindrome(int pal)
{
    int p[MAX],t=-1,r,b=0,val=0,count,i;
    while(pal>0)
    {
        r = pal%10;
        pal /= 10;
        if(t == MAX-1)
            printf("Overflow!\n");
        else
        {
            t += 1;
            p[t] = r;
        }
            
    }
    int mid = (int)((t + b)/2);
    for(i=t;i>=mid;i--)
    {
        val = p[i];
        t -= 1;
        if(val == p[b])
        {
            b ++;
            count = 1;
        }
        else
            count = 0;
    }
    if(count == 1)
        printf("The entered number is a palindrome.\n");
    else
        printf("The entered number is not a palindrome.\n");          
}
void flow()
{
    if(top == MAX-1)
        printf("Stack Overflow!!\n");
    else if( top == -1)
        printf("Stack Underflow!!\n");
    else
        printf("All OK");
}
void status()
{
    int i;
    printf("The current stack is:\n");
    for(i=top;i>=0;i--)
    {    
        printf("%d\n",st[i]);
    }
}
    
Program to convert infix expression to postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 30
char st[MAX];
int top = -1;
void push(char c){
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else{
        top += 1;
        st[top] = c;
    }
}
char pop(){
    char val;
    if (top == -1)
        printf("Stack Underflow\n");
    else{
        val = st[top];
        top -= 1;
        return val;
    }
}
char peek(){
    return st[top];
}
int prec(char c){
    if (c == '^')
        return 3;
    else if (c =='/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int inf_to_post(char s[]){
    int i,j=-1;
    int l = strlen(s);
    char result[l];
    for(i=0;s[i];++i)
    {
        char c = s[i];
        if(isalnum(c)){
            result[++j] = c;
        }
        else if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while(top != -1 && peek() != '('){
                result[++j] = pop();
            }
            if(top != -1 && peek() != '('){
                return -1;
            }
            else
                pop();
        }
        else{
            while(top != -1 && prec(c) <= prec(peek()))
                result[++j] = pop();
            push(c);
        }
    }        
    while (top != -1)
        result[++j] = pop();
    result[++j] = '\0';
    printf("%s\n",result);
}    
void main()
{
    int x;
    char input[20];
    printf("Enter an infix expression to convert into postfix notation\n");
    gets(input);
    inf_to_post(input);
}    
    

