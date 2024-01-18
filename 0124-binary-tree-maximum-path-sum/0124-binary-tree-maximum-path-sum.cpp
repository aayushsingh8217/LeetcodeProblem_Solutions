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
    int maxPathSum(TreeNode* root) {
       if(root==NULL)
           return 0;
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
    int solve(TreeNode* root,int & res)
    {
        if(root==NULL)
            return 0;
        
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        int temp=max(max(l,r)+root->val,root->val);
        int ans=max(temp,l+r+root->val);
        res=max(ans,res);
        
        return temp;
    }
};