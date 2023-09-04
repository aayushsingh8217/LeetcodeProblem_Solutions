/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //slow and fast pointer
        if (!head || !head->next) {
        return false; 
        }
        
        ListNode *slow=head;
        ListNode *fast=head->next;
        
        //both fast and fast--> next exists
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                return true;
        }
        return false;
    }
};