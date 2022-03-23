#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head, int data)
{
	
    struct Node* newnode =
            (struct Node*) malloc(sizeof(struct Node));
 
    newnode->data  = data;
    newnode->next = (*head);
    (*head)    = newnode;
}
int Count(struct Node* head)
{
    int count = 0;  
    struct Node* current = head;  
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void printList(struct Node *head)
{
  while (head != NULL)
  {
     printf(" %d ", head->data);
     head = head->next;
  }
}
int main()
{
    struct Node* head = NULL;
 
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    printf("linked list is\n");
    printList(head);
    printf("\ncount of nodes is %d", Count(head));
    return 0;
}
