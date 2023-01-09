#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<stdbool.h>

struct Node
{
    int info;
    struct Node *link;
};
struct Node *first;

void insert_at_beg()
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d", &ptr->info);
    if (first == NULL)
    {
        first = ptr;
        ptr->link = ptr;
    }

    else
    {
        struct Node *temp;
        temp = first;
        while (temp->link != first)
        {
            temp = temp->link;
        }
        temp->link = ptr;
        ptr->link = first;
        first = ptr;
    }
}

void insert_at_end()
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter thr data\n");
    scanf("%d", &ptr->info);
    if (first == NULL)
    {
        first = ptr;
        ptr->next = ptr;
    }
    else
    {
        struct Node *temp;
        temp = first;
        while (temp->link != first)
        {
            temp = temp->link;
        }
        temp->link = ptr;
        ptr->link = first;
    }
}

void insert_after_given_data()
{
    struct Node *ptr;
    int data;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter thr data\n");
    scanf("%d", &ptr->info);
    printf("Enter the data after which you want to insert the element\n");
    scanf("%d", &data);
    struct Node *temp = first;
    while (temp->info != data)
    {
        temp = temp->link;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}

void deletion_at_beg()
{
    struct Node *temp = first;
    struct Node *ptr = first;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        while (temp->link != first)
        {
            temp = temp->link;
        }
        temp->link = ptr->link;

        first = ptr->link;

        free(ptr);
    }
}

void deletion_at_end()
{
    struct Node *temp = first;
    struct Node *ptr;
    if (first == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (temp->link != first)
        {
            ptr = temp;
            temp = temp->link;
        }
        ptr->link = first;
        free(temp);
    }
}

void deletion_at_given_data()
{
    struct Node *temp = first;
    struct Node *ptr;
    int data;
    printf("Enter the element which you want to delete\n");
    scanf("%d", &data);

    while (temp->info != data)
    {
        ptr = temp;
        temp = temp->link;
    }
    ptr->link = temp->link;
    free(temp);
}

void display()
{
    struct Node *temp = first;
    do
    {
        printf("%d ", temp->info);
        temp = temp->link;
    } while (temp != first);
}

bool is_a_circular_linked_list(){
   struct Node* temp = first;
   struct Node* ptr = first;
   while(temp != NULL && temp->link != NULL)
   {
       temp = temp->link->link;
       ptr = ptr->link;
       if(temp == ptr)
       {
           printf("Given list is a circular linked list\n");
           return true;
       }
   }
    printf("Given list is not a circular linked list\n");
    return false;
}
int main()
{
    struct Node *first = NULL;
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert element at begining\n2.Insert element at end\n3.Insert element after given data\n4.Delete element from the Beginning\n5.Delete element from end\n6.Delete element after specified data\n7.Detection of circular linked list\n8.Display\n9.Exit\n");
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
            is_a_circular_linked_list();
            break;
        case 8:
            display();
            break;    
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
    return 0;
}
