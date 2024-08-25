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
    TreeNode* balanceBST(TreeNode* root) {
     vector<int> in;
     inorder(in,root);
    return  buildT(in,0,in.size()-1);   
    }
    void inorder(vector<int> & in, TreeNode * root)
    {
        if(!root)
        return;
        inorder(in,root->left);
        in.push_back(root->val);
        inorder(in, root->right);
    }
    TreeNode* buildT(vector<int>& in,int s,int e)
    {
        if(s>e)
        return NULL;

        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=buildT(in,s,mid-1);
        root->right=buildT(in,mid+1,e);
        return root;
    }
    
};