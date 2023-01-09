#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first;


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


void make_cycle()
{
    struct node *temp = first;
    struct node *ptr;
    int count = 1;
    int pos;
    while(temp->link != NULL)
    {
        if(pos == count)
        {
            ptr = temp;
        }
        temp = temp->link;
        count++;
    }
    temp->link = ptr;
}

void detect_cycle()
{
    struct node *slow_ptr = first;
    struct node *fast_ptr = first;
    while(fast_ptr != NULL && fast_ptr->link != NULL)
    {
        if(slow_ptr == fast_ptr)
        {
            printf("There is no loop in the given linked list \n");
            return;
        } 
        fast_ptr = fast_ptr->link->link;
        slow_ptr = slow_ptr->link;
    }
    printf("We detect a loop in the given linked list \n");
    return;
}

void detectAndRemoveLoop()
{
	// If list is empty or has only one node without loop
	if (first == NULL || first->link == NULL)
    {
		return;
    }

	struct node *slow = first, *fast = first;

	// Move slow and fast 1 and 2 steps ahead respectively.
	slow = slow->link;
	fast = fast->link->link;

	// Search for loop using slow and fast pointers
	while (fast != NULL && fast->link != NULL) {
		if (slow == fast)
        {
			break;
        }
		slow = slow->link;
		fast = fast->link->link;
	}

	/* If loop exists */
	if (slow == fast) {
		slow = first;

		// this check is needed when slow and fast both meet
		// at the head of the LL eg: 1->2->3->4->5 and then
		// 5->next = 1 i.e the head of the LL
		if (slow == fast){
			while (fast->link != slow)
            {
				fast = fast->link;
            }
        }
		else {
			while (slow->link != fast->link) {
				slow = slow->link;
				fast = fast->link;
			}
		}

		/* since fast->next is the looping point */
		fast->link = NULL; /* remove loop */
	}
}


void middle_element()
{
    struct node *slow_ptr = first;
    struct node *fast_ptr = first;
    if(first != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->link != NULL)
        {
            fast_ptr = fast_ptr->link->link;
            slow_ptr = slow_ptr->link;
        }
        printf("\nThe middle element is : %d\n",slow_ptr->info);
    }
}


void reverse_linked_list()
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
  insert_at_end();
  insert_at_end();
  insert_at_end();   
  insert_at_end();
  reverse_linked_list();
  display();
  middle_element();  
//   int pos;
//   printf("Enter the position where you want to make cycle \n");
//   scanf("%d",&pos);
//   make_cycle();
//   detect_cycle();
//   detectAndRemoveLoop();
  display();


    return 0;
}
