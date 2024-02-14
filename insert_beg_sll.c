// C program to show inserting a node
// at front of given Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
	int data;
	struct Node* next;
};

/* Function to insert a new node at the beginning of the linked list */
void insertAtFront(struct Node** head_ref, int new_data)
{

	// 1. allocate node
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	// 2. put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point
	// to the new node
	(*head_ref) = new_node;
}


void printList(struct Node* node)
{
	while (node != NULL) {
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");
}


int main()
{

	struct Node* head = NULL;

	insertAtFront(&head, 1);
	insertAtFront(&head, 2);
	insertAtFront(&head, 3);
	insertAtFront(&head, 4);
	insertAtFront(&head, 5);
	insertAtFront(&head, 6);

	printf("After inserting nodes at their front: ");
	printList(head);

	return 0;
}
