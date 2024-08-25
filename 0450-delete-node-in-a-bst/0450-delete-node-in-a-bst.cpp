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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return root;

        else if(root->val==key)
        {
            if(!root->left && !root->right)
            return NULL;

            else if(root->left && root->right)
            {
                TreeNode * temp=utility(root->left);
                root->val=temp->val;
                root->left=deleteNode(root->left,root->val);
            }
            else if(root->left)
            return root->left;

            else 
            return root->right;


        }
        else
        {
            if(root->val>key)
            {
                root->left=deleteNode(root->left,key);

            }
            else
            {
                root->right=deleteNode(root->right,key);
            }
        }
        return root;
    }
    TreeNode* utility(TreeNode* root)
    {
        if(!root->right)
        return root;

        return utility(root->right);
    }
};