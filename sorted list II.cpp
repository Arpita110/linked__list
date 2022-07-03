 /*
 Remove Duplicates from Sorted List II
 Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/
 
 ListNode* deleteDuplicates(ListNode* head) {
       map<int,int> mp;
        ListNode* temp=head;
        while(temp)
        {
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* ptr=new ListNode();
        ListNode* start=ptr;
        temp=head;
        while(temp)
        {
            if(mp[temp->val]==1)
            {
                ptr->next=new ListNode(temp->val);
                ptr=ptr->next;
            }
            temp=temp->next;
            
        }
        return start->next;
     
    }
