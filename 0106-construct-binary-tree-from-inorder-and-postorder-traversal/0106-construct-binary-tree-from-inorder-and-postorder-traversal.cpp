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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* solve(vector<int>& in, vector<int>& post,int is,int ie,int ps,int pe)
    {
        if(is>ie)
        return NULL;

        int rootd=post[pe];
        int idx=-1;

        for(int i=is;i<=ie;i++)
        {
            if(in[i]==rootd)
            {
                idx=i;
                break;
            }
        }


    int lis=is;
    int lie=idx-1;
    int lps=ps;
    int lpe=lie-lis+lps;

    int ris=idx+1;
    int rie=ie;
    int rps=lpe+1;
    int rpe=pe-1;

    TreeNode* root=new TreeNode(rootd);
    root->left=solve(in,post,lis,lie,lps,lpe);
    root->right=solve(in,post,ris,rie,rps,rpe);

    return root;

    }
};