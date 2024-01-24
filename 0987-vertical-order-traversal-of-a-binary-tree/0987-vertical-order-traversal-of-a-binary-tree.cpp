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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        map<int, vector<pair<int, int>>> columnNodes; 
        queue<pair<TreeNode*, pair<int, int>>> q; 

        q.push({root, {0, 0}});

        while (!q.empty()) {
            int size = q.size();
            map<int, vector<pair<int, int>>> tempColumnNodes;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();

                tempColumnNodes[col].push_back({row, node->val});

                if (node->left) {
                    q.push({node->left, {row + 1, col - 1}});
                }
                if (node->right) {
                    q.push({node->right, {row + 1, col + 1}});
                }
            }

            for (auto& it : tempColumnNodes) {
                sort(it.second.begin(), it.second.end());
                for (auto& pair : it.second) {
                    columnNodes[it.first].push_back(pair);
                }
            }
        }

        for (auto& it : columnNodes) {
            vector<int> columnValues;
            for (auto& pair : it.second) {
                columnValues.push_back(pair.second);
            }
            result.push_back(columnValues);
        }

        return result;    
    }
};