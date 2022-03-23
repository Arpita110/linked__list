#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node* next;
};

void push(struct Node** head, int key)
{
   
    struct Node* newnode =(struct Node*) malloc(sizeof(struct Node));
    newnode->key  = key;
    newnode->next = (*head);
    (*head)    = newnode;
}
 
 int search(struct Node* head, int x)
{
    struct Node* current = head; 
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}
int printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->key);
     node = node->next;
  }
}

int main()
{
    struct Node* head = NULL;
    int x = 21;
 
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    printf("\n Created Linked list is: ");
    printList(head);
    printf("\n search element %d  in Linked list is:\n ",x); 
    search(head, 21)? printf("Yes,present") : printf("Not present");
    return 0;
}
