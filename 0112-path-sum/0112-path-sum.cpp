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
int sum=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(!root)
        // return false;

        // if(root->left==NULL && root->right==NULL && root->val==targetSum)
        // return true;

        // bool l=hasPathSum(root->left,targetSum-root->val);
        // bool r=hasPathSum(root->right,targetSum-root->val);

        // return l||r;

         if(!root)
        return false;

        sum += root->val;

        if(root->left==NULL && root->right==NULL && sum==targetSum)
        return true;

        bool l=hasPathSum(root->left,targetSum);
        bool r=hasPathSum(root->right,targetSum);

        sum -= root->val;

        return l||r;
    }
};