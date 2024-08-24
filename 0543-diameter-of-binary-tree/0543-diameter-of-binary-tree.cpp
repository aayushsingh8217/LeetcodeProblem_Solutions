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
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL)
//             return 0;
//         int res=INT_MIN;
//         solve(root,res);
//         return res-1;
//     }
//     int solve(TreeNode* root,int& res)
//     {
//         if(root==NULL)
//             return 0;
        
//         int l=solve(root->left,res);
//         int r=solve(root->right,res);
        
//         int temp=max(l,r)+1;
//         int ans=max(l+r+1,temp);
//         res=max(res,ans);
        
//         return temp;
//     }
    class Solution {
public:
int maxD=0;
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxD;
    }
    int solve(TreeNode* root)
    {
        if(!root)
        return 0;

        int l=solve(root->left);
        int r=solve(root->right);

        maxD=max(maxD,l+r);
        return max(l,r)+1;
    }
};