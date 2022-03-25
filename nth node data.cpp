#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
 

struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head, int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
 
    newnode->data = data;
    newnode->next = (*head);
    (*head) = newnode;
}
 
int GetNode(struct Node* head, int index)
{
 
    struct Node* current = head;
 
    int count = 0;
    while (current != NULL) 
	{
        if (count == index)
        return (current->data);
        count++;
        current = current->next;
    }
 
}
int main()
{
 
    
    struct Node* head = NULL;
 
    push(&head, 1);
    push(&head, 6);
    push(&head, 8);
    push(&head, 29);
    push(&head, 11);
 
    printf("Element at index 2 is %d", GetNode(head, 2));
    return 0;
}
