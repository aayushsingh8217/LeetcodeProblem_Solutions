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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* anupma=new ListNode(0,head);
        for (ListNode* pre = anupma; pre->next;) {
            if (st.count(pre->next->val)) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return anupma->next;

    }
};