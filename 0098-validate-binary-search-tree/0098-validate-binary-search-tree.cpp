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
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
    bool solve(TreeNode* root, long minr,long maxr)
    {
        if(root==NULL)
        return true;

        if(root->val<=minr || root->val>=maxr)
        return false;

        return (solve(root->left,minr,root->val) && solve(root->right,root->val,maxr));
    }
};