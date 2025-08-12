class Solution {
public:
    string removeDuplicates(string s) {
        // identification : how stack?
        // sequnece of characters and a past for future dependent answer is needed 
        // adjacency : monotonic : backtrack/undo recent actions : balanced type questions
        string res="";
        stack <char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            int flag=0;
            while(!st.empty() && s[i]==st.top())
            {
                st.pop();
                flag=1;
            }
            if(flag==1)
            continue;
            else
            st.push(s[i]);
        }
        while(!st.empty())
        {
            res = res+st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};