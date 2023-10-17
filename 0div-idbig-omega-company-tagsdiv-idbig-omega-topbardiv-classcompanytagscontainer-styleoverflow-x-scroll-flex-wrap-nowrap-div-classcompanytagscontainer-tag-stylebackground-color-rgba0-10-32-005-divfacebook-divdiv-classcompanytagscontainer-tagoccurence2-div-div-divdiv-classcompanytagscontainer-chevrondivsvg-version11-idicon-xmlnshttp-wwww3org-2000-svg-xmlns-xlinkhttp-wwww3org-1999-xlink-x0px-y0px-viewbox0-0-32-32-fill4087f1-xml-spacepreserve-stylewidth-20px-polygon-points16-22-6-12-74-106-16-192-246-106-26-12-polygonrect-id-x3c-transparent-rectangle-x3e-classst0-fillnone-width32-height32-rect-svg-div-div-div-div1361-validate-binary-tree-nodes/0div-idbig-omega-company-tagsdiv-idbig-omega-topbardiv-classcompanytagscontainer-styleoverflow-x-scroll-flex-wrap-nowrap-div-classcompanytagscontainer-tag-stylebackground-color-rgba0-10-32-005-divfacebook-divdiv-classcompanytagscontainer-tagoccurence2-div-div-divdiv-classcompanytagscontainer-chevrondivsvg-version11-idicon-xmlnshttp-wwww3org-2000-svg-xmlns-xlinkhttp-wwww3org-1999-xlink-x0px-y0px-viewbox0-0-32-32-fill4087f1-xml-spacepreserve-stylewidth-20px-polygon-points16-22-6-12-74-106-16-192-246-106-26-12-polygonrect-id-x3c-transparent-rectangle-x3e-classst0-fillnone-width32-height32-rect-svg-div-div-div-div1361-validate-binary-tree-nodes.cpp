class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
     set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(i);
        }
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (roots.count(leftChild[i])) {
                    roots.erase(leftChild[i]);
                } else {
                    return false;
                }
            }
            if (rightChild[i] != -1) {
                if (roots.count(rightChild[i])) {
                    roots.erase(rightChild[i]);
                } else {
                    return false;
                }
            }
        }
        
        if (roots.size() != 1) {
            return false;
        }
        
        int root = *roots.begin();
        stack<int> stk;
        set<int> lookup;
        
        stk.push(root);
        lookup.insert(root);
        
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            for (int c : {leftChild[node], rightChild[node]}) {
                if (c < 0) {
                    continue;
                }
                if (lookup.count(c)) {
                    return false;
                }
                lookup.insert(c);
                stk.push(c);
            }
        }
        
        return lookup.size() == n;
    }
};