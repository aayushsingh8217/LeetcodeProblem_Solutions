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
    vector<vector<int>> pathSum(TreeNode* root, int tS) {
        vector<vector<int>> res;
        vector<int> cur;
        if(!root)
        return res;
        cur.push_back(root->val);
        solve(root,cur, res, root->val,tS);
        return res;
    }
    void solve(TreeNode* root,vector<int> cur,vector<vector<int>> & res,int sum,int tS)
    {
        if(root->left==NULL && root->right==NULL && sum==tS)
        {
            res.push_back(cur);
            return;
        }
        if(root->left)
        {
            cur.push_back(root->left->val);
            solve(root->left,cur,res,sum+root->left->val,tS);
            cur.pop_back();
        }
        if(root->right)
        {
            cur.push_back(root->right->val);
            solve(root->right,cur,res,sum+root->right->val,tS);
            cur.pop_back();
        }
    }
};