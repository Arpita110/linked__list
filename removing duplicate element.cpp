#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head, int data)
{
    struct Node* newnode =(struct Node*) malloc(sizeof(struct Node));
    newnode->data  = data; 
    newnode->next = (*head);    
    (*head)    = newnode;
}
void removeDuplicates(struct Node* head)
{
    struct Node* current = head;
    struct Node* next_next;
    if (current == NULL)
       return;
    while (current->next != NULL)
    {
       if (current->data == current->next->data)
       {            
           next_next = current->next->next;
           free(current->next);
           current->next = next_next; 
       }
       else 
       {
          current = current->next;
       }
    }
}
 

void printList(struct Node *node)
{
    while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }
}
int main()
{
    struct Node* head = NULL;
   
    push(&head, 20);
    push(&head, 13);
    push(&head, 13); 
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                   
 
    printf("\n Linked list before duplicate removal  ");
    printList(head);
    
    removeDuplicates(head);
 
    printf("\n Linked list after duplicate removal ");        
    printList(head);           
    return 0;
}
