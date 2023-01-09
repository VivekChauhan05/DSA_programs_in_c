// C++ program to detect and remove loop
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int info;
	struct Node* link;
};
struct Node *first;

struct Node* newNode(int key)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->info = key;
	temp->link = NULL;
	return temp;
}

// A utility function to print a linked list
void printList()
{
	while (first != NULL) {
		printf("%d ", first->info);
		first = first->link;
	}
	printf("\n");
}

// Function to detect and remove loop in a linked list that
// may contain loop
void detectAndRemoveLoop()
{
	// If list is empty or has only one node without loop
	if (first == NULL || first->link == NULL)
    {
		return;
    }
    struct Node *slow = first;
    struct Node *fast = first;

	

	// Move slow and fast 1 and 2 steps ahead respectively.
	slow = slow->link;
	fast = fast->link->link;

	// Search for loop using slow and fast pointers
	while (fast && fast->link) {
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
		if (slow == fast)
			while (fast->link != slow)
				fast = fast->link;
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

/* Driver program to test above function*/
int main()
{
	struct Node* first = newNode(50);
	first->link = first;
	first->link = newNode(20);
	first->link->link = newNode(15);
	first->link->link->link = newNode(4);
	first->link->link->link->link = newNode(10);

	/* Create a loop for testing */
	first->link->link->link->link->link = first->link->link;

	detectAndRemoveLoop();

	printf("Linked List after removing loop \n");
	printList();

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
