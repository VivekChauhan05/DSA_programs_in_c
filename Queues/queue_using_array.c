#include<stdio.h>
#include<stdlib.h>

int queue[6];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
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
        }

    }
    while(choice != 4); 
}


void enqueue()
{
    int item;
    if(rear<5)
    {
        printf("\nEnter the element you want to insert\n");
        scanf("%d",&item);
        if(front == -1)
        {
            front = front + 1;
            rear = rear + 1;  
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = item;
    }
    else
    {
        printf("\nQueue is full\n");
    }

}

void dequeue()
{
    int item;
    if(front != -1)
    {
        item = queue[front];
        if(front == rear)
        {
            printf("\nDeleted element is %d", item);
            front = front -1;
            rear = rear -1;
            
        }
        else
        {
            front = front + 1;
            printf("\nDeleted element is %d", item);
        }
    }

    else

    {
        printf("\nQueue is empty\n");
    }
        
}

void display()
{
   if(front == -1  &&rear == -1)
   {
      printf("\nQueue is empty\n");
   }
   else
   {
       printf("Elements in the queue are \n");
       for(int i = front;i<= rear;i++)
       {
           printf("%d ",queue[i]);
       }
   }
}


