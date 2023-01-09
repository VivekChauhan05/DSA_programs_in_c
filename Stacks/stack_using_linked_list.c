#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node {
    int info;
    struct node *link;
};
struct node *top = NULL;

void push()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted ");
    scanf("%d",&newNode->info);
    newNode->link = top;
    top = newNode;
}

void pop()
{
   if(top == NULL)
   {
       printf("Stack is empty\n");
       return;
   }
   else
   {
      printf("The popped element is %d\n",top->info);
      top = top->link;
   }
}

void display()
{
    struct node *temp = top;
    if(temp == NULL)
    {
        printf("Stack is empty");
        return;
    }
    while(temp!= NULL)
    {
        printf("%d\n",temp->info);
        temp = temp->link;
    }

}


void push();
void pop();
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
        printf("\n1 : PUSH");
        printf("\n2 : POP");
        printf("\n3 : DISPLAY");
        printf("\n4 : EXIT");
    
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
            case 1:
               push();
                break;
            case 2:
                pop();
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
