class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string &t:tokens)
        {
            if(t=="+"|| t=="-" || t=="*" || t=="/")
            {
                int b=nums.top();
                nums.pop();
                int a=nums.top();
                nums.pop();
                int op=m[t](a,b);
                // if(t=="+"){
                // op=a+b;
                // }
                // else if(t=="-")
                // op=a-b;
                // else if(t=="*")
                // op=(long)a*(long)b;
                // else
                // op=a/b;
                nums.push(op);

            }
            else
            {
                nums.push(stoi(t));
            }
        }
        return nums.top();
        
    }
    unordered_map<string,function<int(int,int)>> m=
    {
        {"+",[](int a,int b){return a+b;}},
        {"-",[](int a,int b){return a-b;}},
        {"*",[](int a,int b){return (long)a*(long)b;}},
        {"/",[](int a,int b){return a/b;}},

    };
};