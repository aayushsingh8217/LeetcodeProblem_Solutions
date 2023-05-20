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
    //Amazon
    int pairSum(ListNode* head) {
  vector<int> values;

    // Store the values of the linked list nodes in an array
    ListNode* current = head;
    while (current != nullptr) {
        values.push_back(current->val);
        current = current->next;
    }

    int n = values.size();
    int maxSum = 0;

    // Calculate the twin sums using the array
    for (int i = 0; i < n / 2; i++) {
        int twinSum = values[i] + values[n - 1 - i];
        maxSum = std::max(maxSum, twinSum);
    }

    return maxSum;
        
    }
};