class Solution {
public:
    bool backspaceCompare(string s, string t) {
     stack<char> s_stack;
    stack<char> t_stack;
    for (char c : s) {
        if (c != '#') {
            s_stack.push(c);
        } else if (!s_stack.empty()) {
            s_stack.pop();
        }
    }
    for (char c : t) {
        if (c != '#') {
            t_stack.push(c);
        } else if (!t_stack.empty()) {
            t_stack.pop();
        }
    }
// Compare 
    if (s_stack.size() != t_stack.size()) {
        return false;
    }

    while (!s_stack.empty()) {
        if (s_stack.top() != t_stack.top()) {
            return false;
        }
        s_stack.pop();
        t_stack.pop();
    }

    return true;   
    }
};