class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       char res = NULL;
       int s = 0, e= letters.size()-1;
       while(s<=e)
       {
            int m = s+(e-s)/2;
            if(letters[m] < target)
            s= m+1;
            else if(letters[m] > target)
            {
                res = letters[m];
                e = m-1;
            }
            else  if(letters[m]==target)
            {
                s=m+1;
                
            }
       } 
       return res!= NULL? res: letters[0];
    }
};