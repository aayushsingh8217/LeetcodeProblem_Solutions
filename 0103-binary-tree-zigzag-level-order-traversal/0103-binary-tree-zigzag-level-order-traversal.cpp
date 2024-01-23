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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //---------------STACK--------------
//          vector<vector<int>> res;
//         stack<TreeNode*> st, stn;
//         TreeNode* curr;
//         if(!root) 
//         return res;
//         bool pos = true;
//         st.push(root);
//         while(!st.empty()){
//             int size = st.size();
//             vector<int> lvl(size);
//             bool nxtpos=!pos;
//             for(int i = 0; i <size; ++i){
//                 curr= st.top(); st.pop();
//                 lvl[i] =curr->val;
//                 TreeNode* child1 = curr->left;
//                 TreeNode* child2 = curr->right;
//                 if(nxtpos){
//                     swap(child1, child2);
//                 }
//                 if(child1)
//                  stn.push(child1);
//                 if(child2) 
//                 stn.push(child2);
                
//             }
//             swap(st, stn);
//             pos= nxtpos;
//             res.push_back(lvl);
//         }
        
//         return res;
        
        //-----------QUEUE BFS-------------
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int flag=1;
        while(!q.empty())
        {
            vector<int> v;
            int n=q.size();
            while(n--)
            {
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left )
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            if(flag)
            {
                flag=0;
               
                res.push_back(v);
            }
            else
            {
                flag=1;
                 reverse(v.begin(),v.end());
                res.push_back(v);
            }
        }
        return res;
    }
};