#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
struct  node*front = NULL;
struct node*rear = NULL;

void enqueue()
{
    int val;
    printf("Enter the data to be inserted\n");
    scanf("%d",&val);
    struct node *Newnode;
    Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->info = val;
    if(front == NULL && rear == NULL)
    {
        Newnode->link = Newnode;
        rear = Newnode;
        front = Newnode;
    }
    else
    {
        Newnode->link = front;
        rear->link = Newnode;
        rear = Newnode;
    }
}


void dequeue()
{
    struct node *temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front->link != NULL)
    {
        printf("Deleted element is %d",front->info);
        front = front->link;
        rear->link = front;
        free(temp);
    }
    else
    {
        printf("Deleted element is %d",front->info);
        front = NULL;
        rear = NULL;
        free(temp);
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
        do{
            printf("%d ",temp->info);
            temp = temp->link;
        }
        while(temp != front);
    }
}
void main()
{   
    char ch;
    int choice;
    do
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1 : ENQUEUE");
        printf("\n2 : DEQUEUE");
        printf("\n3 : DISPLAY");
        printf("\n4 : EXIT");
    
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
            case 1:
               enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }

    }
    while(choice != 4);
}