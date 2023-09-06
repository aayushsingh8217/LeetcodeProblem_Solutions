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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
    
        
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }
    
   
    int part_size = length / k;
    int extra_nodes = length % k;
    
    current = head;
    for (int i = 0; i < k; i++) {
        result.push_back(current);
        int part_length = part_size + (i < extra_nodes ? 1 : 0);
        
    
        for (int j = 0; j < part_length - 1; j++) {
            current = current->next;
        }
        
       
        if (current) {
            ListNode* temp = current->next;
            current->next = NULL;
            current = temp;
        }
    }
    
    return result; 
    }
};