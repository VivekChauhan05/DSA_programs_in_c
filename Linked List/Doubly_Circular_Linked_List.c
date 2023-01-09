#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
};
struct Node *first;

void insert_at_beg()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d", &ptr->info);
    if (first == NULL)
    {
        first = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    }
    else
    {
        ptr->next = first;
        ptr->prev = first->prev;
        first->prev->next = ptr;
        first->prev = ptr;
        first = ptr; 
    }
}

void insert_at_end()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&ptr->info);
    if (first == NULL)
    {
        first = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    }
       else
{
    ptr->next = first;
    ptr->prev = first->prev;
    first->prev->next = ptr;
    first->prev = ptr; 
}
}

void insert_after_given_data()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter the data\n");
    scanf("%d",&ptr->info);
    printf("Enter the data after which you want to insert the element\n");
    scanf("%d", &data);
    struct Node *temp = first;

    while (temp->info != data)
    {
        temp = temp->next;
    }
    ptr->prev = temp;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    temp->next = ptr;
}

void deletion_at_beg()
{
    struct Node *temp = first;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if (first->next == NULL)
    {
        first = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        first = first->next;
        free(temp);
    }
}

void deletion_at_end()
{
    struct Node *temp;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if (first->next == NULL)
    {
        first = NULL;
    }

    else
    {
        temp = first->prev;
        first->prev->prev->next = first;
        first->prev = first->prev->prev;
        free(temp);
    }
}

void deletion_at_given_data()
{
    struct Node *temp= first;
    int data;
    printf("Enter the element which you want to delete\n");
    scanf("%d", &data);
    while (temp->info != data)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    struct Node *temp = first;
    do
    {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != first);
}

int main()
{
    struct Node *first = NULL;
    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert element at begining\n2.Insert element at end\n3.Insert element after given data\n4.Delete element from the Beginning\n5.Delete element from end\n6.Delete element after specified data\n7.Display\n8.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_beg();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_after_given_data();
            break;
        case 4:
            deletion_at_beg();
            break;
        case 5:
            deletion_at_end();
            break;
        case 6:
            deletion_at_given_data();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
    return 0;
}
