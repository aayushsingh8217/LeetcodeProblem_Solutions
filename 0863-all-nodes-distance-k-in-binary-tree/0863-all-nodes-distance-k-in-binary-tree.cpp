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
     vector<int> res;
    
    
    unordered_map<TreeNode*, TreeNode*> parentMap;
    buildParentMap(root, NULL, parentMap);
    queue<TreeNode*> q;
    q.push(target);
    
    unordered_map<TreeNode*, bool> visited;
    visited[target] = true;
    
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        if (level == k) {
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);
            }
            break;
        }
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            
            TreeNode* parent = parentMap[node];
            if (parent && !visited[parent]) {
                q.push(parent);
                visited[parent] = true;
            }
        }
        
        level++;
    }
    
    return res;   
    }
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    if (node == NULL)
        return;
    
    parentMap[node] = parent;
    
    buildParentMap(node->left, node, parentMap);
    buildParentMap(node->right, node, parentMap);
}
};