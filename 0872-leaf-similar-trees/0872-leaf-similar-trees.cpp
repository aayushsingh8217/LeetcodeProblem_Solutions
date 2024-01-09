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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> lefttree,righttree;
        takeleafnode(root1,lefttree);
        takeleafnode(root2,righttree);
        if(lefttree==righttree)
        return true;
        else
        return false;
    }
 void takeleafnode(TreeNode *root,vector <int> &num)
 {
     if(root==NULL)
     {
         return;
     }
     if(root->left==NULL and root->right==NULL)
     {
         num.push_back(root->val);
         return;
     }
     takeleafnode(root->left,num);
     takeleafnode(root->right,num);
 }
};