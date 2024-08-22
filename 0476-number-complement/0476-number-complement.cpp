class Solution {
public:
    int findComplement(int num) {
       if(num==0)
       return 1;
       else if(num==1)
       {
        return 0;
       }
       else
       {
        int nofb=(int)(log2(num))+1;
        for(int i=0;i<nofb;i++)
        {
            num=num^(1<<i);
        }
        return num;
       }
    }
};