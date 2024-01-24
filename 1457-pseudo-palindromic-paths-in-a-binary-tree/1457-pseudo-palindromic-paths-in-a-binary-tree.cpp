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
    int pseudoPalindromicPaths (TreeNode* root) {
      vector<int> count(10, 0);
        int result = 0;
        dfs(root, count, result);
        return result;  
    }
      void dfs(TreeNode* node, vector<int>& count, int& result) {
        if (node == nullptr) {
            return;
        }
        count[node->val]++;
        if (node->left == nullptr && node->right == nullptr) {
            if (isPseudoPalindromic(count)) {
                result++;
            }
        }
        dfs(node->left, count, result);
        dfs(node->right, count, result);

        count[node->val]--;
    }
     bool isPseudoPalindromic(vector<int>& count) {
        int oddCount = 0;

        for (int i = 1; i <= 9; ++i) {
            if (count[i] % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }
};