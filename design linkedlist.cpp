/*
DESIGH LINKED LIST
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
*/


class Node {
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = nullptr;
    } 
}; 
class MyLinkedList {
public:
   
    int size; 
    Node *head;
    MyLinkedList() {
       
       size = 0;
       head = nullptr;
    }
    
    int get(int index) 
    {   
        if(index < 0 || index >= size) 
            return -1;
        Node *target = head;
        for(int i = 0; i < index; i++)
            target = target->next;
        return target->val;
    }
    
    void addAtHead(int val) 
    {
        Node *newNode = new Node(val);
        if(!head) 
            head = newNode;
        else{
            newNode->next = head; 
            head = newNode;
        }
        size++; 
    }
    
    void addAtTail(int val) 
    {
        Node *newNode = new Node(val);
        if(!head) 
            head = newNode;
        else{
           
            Node *tail = head;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = newNode;
        }
        size++; 
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index < 0 || index > size) 
            return;
        else if(index == 0)
            addAtHead(val);
        else
        {
            Node* newNode = new Node(val);
            Node *prev = head;
            for(int i = 1; i < index; i++)
                prev = prev->next;
            Node *after = prev->next;
            prev->next = newNode;
            newNode->next = after;
        }
        size++; 
    }
    
    void deleteAtIndex(int index) 
    {  
        if(index < 0 || index >= size) 
            return;
        else if(index == 0)
            head = head->next;
        else
        {
            Node *prev = head;  
            for(int i = 1; i < index; i++)
                prev = prev->next;
            Node *target = prev->next;
            prev->next = target->next;
           
            delete target;
        }
        size--;
    }
