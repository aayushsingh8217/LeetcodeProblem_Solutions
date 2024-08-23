/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     queue<TreeNode*> q;
        q.push(root);

        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,bool> vis;

        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();

            if(temp->left)
            {
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                parent[temp->right]=temp;
            }

        }

        int distance=0;
        q.push(target);
        vis[target]=true;
        while(!q.empty())
        {
            int s=q.size();
            if(distance++==k)
            {
                break;
            }
            while(s--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(parent[temp] && !vis[parent[temp]])
                {
                    q.push(parent[temp]);

                    vis[parent[temp]]=true;
                }
            }
        }
          vector<int> ans;

        while(!q.empty())

        {

            ans.push_back(q.front()->val);

            q.pop();

        }

        

        return ans;
    }
};