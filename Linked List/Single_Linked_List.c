#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node * link;
};
struct Node*first;

void insert_at_beg()
{
    struct Node*ptr;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&ptr->info);
    
    if(first == NULL)
    {
        ptr->link = NULL;
    }
    else{
        ptr->link = first;
    }
    first = ptr;
}

void insert_at_end()
{
    struct Node*ptr,*cpt;
    ptr =(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&ptr->info);
    if(first == NULL)
    {
        first = ptr;
    }
    else
    {
        cpt = first;
        while(cpt->link != NULL)
        {
            cpt = cpt->link;
        }
        cpt->link = ptr;
    }
    ptr->link = NULL;
}

void insert_after_given_data()
{
    struct Node*ptr,*temp;
    int data;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&ptr->info); 
    printf("Enter the data after which you want to insert the element\n");
    scanf("%d",&data);
    temp = first;
    while(temp->info != data)
    {
        temp = temp->link;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}

void deletion_at_beg()
{
    struct Node*temp;
    if(first == NULL)
    {
        return;
    }
    else
    {
        temp = first;
        first = temp->link;
        free(temp);
    }
}    


void deletion_at_end()
{
    struct Node*temp,*cpt;
    if(first == NULL)
    {
        printf("List is empty");
    }
    else if(first->link == NULL)
    {
        temp = first;
        first = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        while(temp->link != NULL)
        {
            cpt = temp;
            temp= temp->link;
        }
        cpt->link = NULL;
        free(temp);
    } 
}

void deletion_at_given_data()
{
    struct Node*temp,*cpt;
    int data;
    printf("Enter the element which you want ot delete\n");
    scanf("%d",&data);
    
    if(first == NULL)
    {
        printf("List is Empty");
    }
    else 
    {
        temp = first;
        while(temp->info != data)
        {
            cpt = temp;
            temp = temp->link;
        }
        cpt->link = temp->link;
        free(temp);
    }
    
}


void fun2(struct Node * first)
{
    if(first == NULL)
    return;
    printf("%d",first->info);
    if(first->link!=NULL)
    fun2(first->link->link);
    //printf("%d",first->info);
}

void display()
{
    struct Node*temp;
    temp = first;
    while(temp!= NULL)
    {
        printf("%d ",temp->info);
        temp = temp->link;
    }
}

int main()
{
    struct Node*first = NULL;
    int choice =0;  
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert element at beginning\n2.Insert element at end\n3.Insert element after given data\n4.Delete element from the Beginning\n5.Delete element from end\n6.Delete element after specified data\n7.Fun2\n8.Display\n9.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
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
            fun2(first);
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

