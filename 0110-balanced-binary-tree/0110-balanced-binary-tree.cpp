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
bool ans;
    bool isBalanced(TreeNode* root) {
       ans=true;
       int temp=func(root);
       return ans; 
    }
    int func(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        if(ans==false)
        return 0;

        int ls=func(root->left);
        int rs=func(root->right);

        if(abs(ls-rs)>1)
        ans=false;

        return 1+max(ls,rs);
    }
};