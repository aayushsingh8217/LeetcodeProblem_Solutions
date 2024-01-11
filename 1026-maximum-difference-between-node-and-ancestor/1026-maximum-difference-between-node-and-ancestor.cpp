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
int diff(TreeNode *root,int maxval,int minval)
{
    if(root==NULL)
    {
        return (maxval-minval);
    }
    minval=min(minval,root->val);
    maxval=max(maxval,root->val);
    return max(diff(root->left,maxval,minval),diff(root->right,maxval,minval));
}
    int maxAncestorDiff(TreeNode* root) {
        int minval=INT_MAX;
        int maxval=0;
       
        return diff(root,maxval,minval);
    }
};