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
    ListNode* swapNodes(ListNode* head, int k) {
       int len = 0;
    ListNode* curr = head;
    while (curr) {
        len++;
        curr = curr->next;
    }

    if (k > len) 
    return head;
    // agar length hi choti padd gyi

    if(len==1)
    return head;// agar sirf ek node hai toh return krdo

    int left_idx = k - 1;//left side se index nikal liya
    int right_idx = len - k;//end se index nikal liya jo swap karna hai


    if (left_idx == right_idx)
     return head;// agar dono kahi mid mein mil rhe hai toh directly return kardo

    ListNode* left_node = head;
    ListNode* right_node = head;
    for (int i = 0; i < left_idx; i++) 
    {
        left_node = left_node->next;// ye ab left index wale node ko point kar rha hai
    }
    for (int i = 0; i < right_idx; i++) 
    {
        right_node = right_node->next;// ye ab back se k-1 index ko point kar rha hai
    }

    int temp = left_node->val;
    left_node->val = right_node->val;
    right_node->val = temp;// swap kar diye generic as f method se

    return head;// return kr diye
    }
};