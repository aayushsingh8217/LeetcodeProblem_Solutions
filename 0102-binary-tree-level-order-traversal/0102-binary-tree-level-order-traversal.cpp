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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //----------------BFS--------
        // vector<vector<int>> res;
        // if(root==NULL)
        //     return res;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty())
        // {
        //     vector<int> singleLvl;
        //     int n=q.size();
        //     while(n--)
        //     {
        //         TreeNode* node=q.front();
        //         q.pop();
        //         singleLvl.push_back(node->val);
        //         if(node->left)
        //             q.push(node->left);
        //         if(node->right)
        //             q.push(node->right);
        //     }
        //     res.push_back(singleLvl);
        // }
        // return res;
        
        //-------------------DFS-----------------
        solve(root,0);
        return res;
    }
    void solve(TreeNode* root,int dep)
    {
        if(root==NULL)
            return ;
        
        if(res.size()==dep)
            res.push_back(vector<int>());
        
        res[dep].push_back(root->val);
        solve(root->left,dep+1);
        solve(root->right,dep+1);
    }
};