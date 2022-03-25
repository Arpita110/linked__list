#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
  void push(struct Node** head, int data)
{
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
  
    newnode->data  = data;
    newnode->next = (*head);
    (*head)    = newnode;
}
 
void moveendToFront(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;
  
    struct Node *secLast = NULL;
    struct Node *last = *head;
  
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = last->next;
    last->next = *head;
    *head = last;
}
  

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
  
int main()
{
    struct Node *head = NULL;
  
    push(&head, 6);
    push(&head, 47);
    push(&head, 3);
    push(&head, 21);
    push(&head, 1);
  
    printf("\n Linked list before moving last to front\n");
    printList(head);
  
    moveendToFront(&head);
  
    printf("\n Linked list after removing last to front\n");
    printList(head);
  
    return 0;
}
