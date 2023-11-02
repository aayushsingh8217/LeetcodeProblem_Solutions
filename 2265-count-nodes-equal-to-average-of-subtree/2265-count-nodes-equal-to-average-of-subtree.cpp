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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count; 
    }
       unordered_map<TreeNode*, pair<int, int>> dfs(TreeNode* node, int& count) {
        if (!node)
            return {};

        unordered_map<TreeNode*, pair<int, int>> subtree_info;
        subtree_info[node] = {node->val, 1};

        if (node->left) {
            auto left_subtree_info = dfs(node->left, count);
            subtree_info[node].first += left_subtree_info[node->left].first;
            subtree_info[node].second += left_subtree_info[node->left].second;
        }

        if (node->right) {
            auto right_subtree_info = dfs(node->right, count);
            subtree_info[node].first += right_subtree_info[node->right].first;
            subtree_info[node].second += right_subtree_info[node->right].second;
        }

        int subtree_average = subtree_info[node].first / subtree_info[node].second;
        if (subtree_average == node->val) {
            count++;
        }

        return subtree_info;
       }
};