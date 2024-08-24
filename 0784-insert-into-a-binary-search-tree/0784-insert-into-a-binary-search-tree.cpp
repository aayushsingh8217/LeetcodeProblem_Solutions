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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // ---------------RECURSIVE CODE-------------------------
        // if(root==NULL)
        // {
        //     TreeNode* ptr=new TreeNode(val);
        //     return ptr;
        // }

        // if(root->val > val)
        // {
        //     root->left=insertIntoBST(root->left,val);
        // }
        // else
        // {
        //     root->right= insertIntoBST(root->right,val);
        // }
        // return root;

        //------------------Iterative CODE-----------------------
        TreeNode* cur,*prev;
        prev=cur=root;

        TreeNode *node=new TreeNode(val);

        if(!root)
        return node;

        while(cur)
        {
            if(val> cur->val)
            {
                prev=cur;
                cur=cur->right;
            }
            else if(val< cur->val)
            {
                prev=cur;
                cur=cur->left;
            }
        }
        if(val<prev->val)
        prev->left=node;
        else
        prev->right=node;
        return root;
    }
};