#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first;

void reverse_linked_list(struct node *head);
bool compareLists(struct node*,struct node*);

void insert_at_beg()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert \n");
    scanf("%d",&ptr->info);

    if(first == NULL)
    {
        first = ptr;
        ptr->link = NULL;
    }
    else
    {
        ptr->link = first;
        first = ptr;
    }
}

void insert_at_end()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert \n");
    scanf("%d",&ptr->info);
    if(first == NULL)
    {
        first = ptr;
    }
    else{
        struct node *temp = first;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link =ptr;
    }
    ptr->link = NULL;
}

bool isPalindrome(struct node *head)
{
    struct node *slow_ptr = first;
    struct node *fast_ptr = first;
    struct node *mid = NULL;
    struct node *prev_slow_ptr = first;
    struct node *second_half;
    bool res = true;
    if(first != NULL && first->link != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->link != NULL)
        {
            fast_ptr = fast_ptr->link->link;
            prev_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->link;
        }

        if(fast_ptr!= NULL)
        {
            mid = slow_ptr;
            slow_ptr = slow_ptr->link;
        }

        second_half = slow_ptr;
        prev_slow_ptr->link = NULL;

        reverse_linked_list(second_half);
        res = compareLists(first,second_half);

        reverse_linked_list(second_half);
        if (mid != NULL) {
			prev_slow_ptr->link = mid;
			mid->link = second_half;
		}
		else
			prev_slow_ptr->link = second_half;
	}
	return res;

}



bool compareLists(struct node *head1,struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->info == temp2->info)
        {
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else
        {
            return 0;
        }
    }

    if(temp1 == NULL && temp2 == NULL)
    {
        return 1;
    }
    return 0;
}

void reverse_linked_list(struct node *first)
{
   struct node *prev = NULL;
   struct node *curr = first;
   struct node *next = NULL;
   if(first == NULL)
   {
       return;
   }
   while(curr != NULL)
   {
      next = curr->link;
      curr->link = prev;

      prev = curr;
      curr = next;
   }
   first = prev;
}


void display()
{
    struct node *temp = first;
    printf("Given linked list is :\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->info);
        temp = temp->link;
    }
    printf("NULL");
}


int main()
{
  struct node*first = NULL;
  insert_at_beg();
  insert_at_end();
  insert_at_end();
  insert_at_end();   
  insert_at_end();

  reverse_linked_list(first);
  display();
//   if(isPalindrome(first))
//   {
//      printf("Given list is palindrome\n");
//   }
//   else
//   {
//      printf("Given list is not palindrome\n");
//   }

  
	isPalindrome(first) ? printf("\nIs Palindrome\n\n")
					: printf("\nNot Palindrome\n\n");

    return 0;
}
