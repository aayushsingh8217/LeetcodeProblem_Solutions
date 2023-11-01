/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
         map<int, int> countMap;
        int maxCount = 0;
        inOrderTraversal(root, countMap, maxCount);
        vector<int> result;
        for (const auto& entry : countMap) {
            if (entry.second == maxCount) {
                result.push_back(entry.first);
            }
        }
        return result;
    }
    void inOrderTraversal(TreeNode* node, map<int, int>& countMap, int& maxCount) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left, countMap, maxCount);
        countMap[node->val]++;
        maxCount = max(maxCount, countMap[node->val]);
        inOrderTraversal(node->right, countMap, maxCount);
    }
};