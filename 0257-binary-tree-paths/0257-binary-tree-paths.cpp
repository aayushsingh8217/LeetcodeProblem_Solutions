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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        if(!root)
        {
            return res;
        }
         solve(root,res,to_string(root->val));
         return res;
    }
   void solve(TreeNode* root,vector<string>& res,string s)
    {
        if(!root->left && !root->right)
        {
            res.push_back(s);
            return;
        }
        if(root->left)
        solve(root->left,res,s+"->"+to_string(root->left->val));
        if(root->right)
        solve(root->right,res,s+"->"+to_string(root->right->val));

    }
};