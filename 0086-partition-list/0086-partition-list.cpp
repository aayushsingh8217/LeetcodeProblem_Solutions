/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode lessThanX(0);  
        ListNode greaterThanOrEqualX(0);  
        ListNode* lessTail = &lessThanX;  
        ListNode* greaterTail = &greaterThanOrEqualX;   
        
        while (head) {
            if (head->val < x) {
                lessTail->next = head;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = head;
                greaterTail = greaterTail->next;
            }
           head=head->next;
        }
        
        lessTail->next = greaterThanOrEqualX.next;
        greaterTail->next = nullptr;  
        
        return lessThanX.next;  
    }
};