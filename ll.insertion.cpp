#include <stdlib.h>
#include<stdio.h>
struct Node
{
  int data;
  struct Node *next;
};
void pushbeg(struct Node** head, int data)
{  
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
    newnode->data  = data;
    newnode->next = (*head);
    (*head)    = newnode;
}

void append(struct Node** head, int data)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head; 
	newnode->data = data;
	newnode->next = NULL;
	if (*head == NULL)
	{
	*head = newnode;
	return;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = newnode;
	return;
}
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
int main()
{
  struct Node* head = NULL;
  pushbeg(&head, 7);
  pushbeg(&head, 5);
  append(&head, 4);
  pushbeg(&head, 1);
  append(&head, 2);
  
  printf("\n Created Linked list is: ");
  printList(head);
 
  return 0;
}
