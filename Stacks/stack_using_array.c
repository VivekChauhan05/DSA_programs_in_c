#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void push(); 
void pop();
void display();
int top =-1;
int Stack[6];

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
void push()
{
    int item;
    if(top==5)
    {
        printf("\nStack overflow\n");
        return;
    }
    else
    {
        printf("\nEnter the element to be inserted\n");
        scanf("%d",&item);
        top = top + 1;
        Stack[top] = item;
    }
}
void pop()
{
    int item;
    if(top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        item = Stack[top];
        printf("Popped element is %d\n",item);
        top = top -1;
    }
    
}
void display()
{
    if(top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nElements in the stack are\n ");
        for (int i = top;i>=0;i--)
        {
            printf("\n%d",Stack[i]);
        }
    }
}
