class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
      if(a.size()<=1)
      return n;

      int j=0;
      for(int i=0;i<n-1;i++)
      {
        if(a[i]!=a[i+1])
        a[j++]=a[i];
      } 
      a[j++]=a[n-1];
      return j;
    }
};