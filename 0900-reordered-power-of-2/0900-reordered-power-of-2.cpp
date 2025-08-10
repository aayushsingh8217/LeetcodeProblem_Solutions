class Solution {
public:
string sortins(int n)
{
    string s = to_string(n);
    sort(s.begin(),s.end());
    return s;
}
    bool reorderedPowerOf2(int n) {
        string s = sortins(n);
        //2^29
        for(int i=0;i<=29;i++)
        {
            if(s == sortins(1<<i))
            return true;
        }
        return false;
    }
};