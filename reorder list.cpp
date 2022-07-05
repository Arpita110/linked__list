 /*
 REORDER LIST 
 Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

*/
void reorderList(ListNode* head) {
       
        while(head)
        {
            ListNode* restOfList = head->next;
            head->next = reverseList(restOfList);
            head = head->next;
        }
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(head)
        {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        }
        return prev;
    }
