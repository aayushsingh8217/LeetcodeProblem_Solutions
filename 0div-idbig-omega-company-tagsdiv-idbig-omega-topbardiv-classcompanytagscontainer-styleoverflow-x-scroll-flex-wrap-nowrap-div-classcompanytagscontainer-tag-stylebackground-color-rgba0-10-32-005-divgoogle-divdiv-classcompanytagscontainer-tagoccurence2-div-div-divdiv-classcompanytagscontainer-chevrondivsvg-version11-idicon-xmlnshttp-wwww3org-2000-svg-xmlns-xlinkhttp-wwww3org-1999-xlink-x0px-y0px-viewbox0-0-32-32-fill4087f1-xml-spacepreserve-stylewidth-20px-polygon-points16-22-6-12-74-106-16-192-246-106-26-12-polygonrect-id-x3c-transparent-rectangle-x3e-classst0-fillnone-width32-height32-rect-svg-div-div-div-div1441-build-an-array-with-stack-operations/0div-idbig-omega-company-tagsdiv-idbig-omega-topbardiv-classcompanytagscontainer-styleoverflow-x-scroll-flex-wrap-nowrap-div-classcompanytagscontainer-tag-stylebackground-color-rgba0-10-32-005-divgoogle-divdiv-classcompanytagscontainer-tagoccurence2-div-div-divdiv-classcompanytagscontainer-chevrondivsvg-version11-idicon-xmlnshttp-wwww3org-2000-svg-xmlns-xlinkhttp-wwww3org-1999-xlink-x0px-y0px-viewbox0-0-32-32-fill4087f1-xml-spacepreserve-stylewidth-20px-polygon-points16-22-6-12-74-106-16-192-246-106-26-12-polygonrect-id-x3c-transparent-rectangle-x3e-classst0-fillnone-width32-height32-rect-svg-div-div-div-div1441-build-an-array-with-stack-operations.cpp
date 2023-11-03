class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
    stack<int> st;
    
   int targetIdx = 0;
    
    for (int i = 1; i <= n && targetIdx < target.size(); ++i) {
        st.push(i);
        operations.push_back("Push");
        
        if (st.top() == target[targetIdx]) {
            targetIdx++;
        } else {
            st.pop();
            operations.push_back("Pop");
        }
    }
    
    return operations;
    }
};