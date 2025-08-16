class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i=0;i<s.size();i++)
        {
            int flag=0;
            char c = s[i];
            if(c=='6')
            { 
                s[i] = '9';
                flag=1;
            }
            if(flag==1)
            break;
        }
        return stoi(s);
    }
};