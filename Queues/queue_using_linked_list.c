#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
struct  node*front = NULL;
struct node*rear = NULL;

void enque()
{
    int val;
    printf("Enter the data to be inserted\n");
    scanf("%d",&val);
    struct node *Newnode;
    Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->info = val;
    if(rear == NULL)
    {
        Newnode->link = NULL;
        rear = Newnode;
        front = Newnode;
    }
    else
    {
        rear->link = Newnode;
        rear = Newnode;
        Newnode->link = NULL;
    }
 
}


void deque()
{
    struct node *temp = front;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front->link != NULL)
    {
        printf("Deleted element is %d",front->info);
        front = front->link;
        free(temp);
    }
    else
    {
        printf("Deleted Element is %d",front->info);
        free(temp);
        front = NULL;
        rear = NULL;
    }
}


void display()
{
    struct node *temp = front;
    if(temp == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->info);
            temp = temp->link;
        }
    }
}


void enque();
void deque();
void display();
void main()
{   
    char ch;
    int choice;
    do
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1 : ENQUE");
        printf("\n2 : DEQUE");
        printf("\n3 : DISPLAY");
        printf("\n4 : EXIT");
    
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
            case 1:
               enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }

    }
    while(choice != 4);
}
