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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           stack<int> stk1, stk2;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* prev = nullptr;
        ListNode* head = nullptr;
        int sum = 0;
        while (!stk1.empty() || !stk2.empty()) {
            sum /= 10;
            if (!stk1.empty()) {
                sum += stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                sum += stk2.top();
                stk2.pop();
            }

            head = new ListNode(sum % 10);
            head->next = prev;
            prev = head;
        }

        if (sum >= 10) {
            head = new ListNode(sum / 10);
            head->next = prev;
        }

        return head;
    }
};