// C program to create a linked list and display the elements in the list

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
    head = new_node; // head will store the address of the first node
}

void delete_node()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void add_at_beginning(int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void add_after(int value, int position)
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void add_before(int value, int position)
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    temp = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void add_at_end(int value)
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list()
{
    struct node *current = head; // current will point to head first
    printf("\n The linked list is: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next; // current is now pointing to the next node
    }
    printf("\n");
}

int main()
{
    int choice, value, position;

    while (1)
    {
        printf("\n 1. Create a node");
        printf("\n 2. Add a node at the beginning");
        printf("\n 3. Add a node after a given node");
        printf("\n 4. Add a node before a given node");
        printf("\n 5. Add a node at the end");
        printf("\n 6. Delete a node");
        printf("\n 7. Display the list");
        printf("\n 8. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter the value of the node: ");
            scanf("%d", &value);
            add_node(value);
            break;
        case 2:
            printf("\n Enter the value of the node: ");
            scanf("%d", &value);
            add_at_beginning(value);
            break;
        case 3:
            printf("\n Enter the value of the node: ");
            scanf("%d", &value);
            printf("\n Enter the position after which the node is to be inserted: ");
            scanf("%d", &position);
            add_after(value, position);
            break;
        case 4:
            printf("\n Enter the value of the node: ");
            scanf("%d", &value);
            printf("\n Enter the position before which the node is to be inserted: ");
            scanf("%d", &position);
            add_before(value, position);
            break;
        case 5:
            printf("\n Enter the value of the node: ");
            scanf("%d", &value);
            add_at_end(value);
            break;
        case 6:
            delete_node();
            break;
        case 7:
            print_list();
            break;
        case 8:
            exit(0);
        default:
            printf("\n Wrong choice");
        }
    }
    return 0;
}