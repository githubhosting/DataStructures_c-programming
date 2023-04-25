/*
 * C program to create a linked list and display the elements in the list
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void add_node(int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void print_list()
{
    struct node *current = head;
    printf("\n The linked list is:");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        add_node(val);
    }
    print_list();
    return 0;
}