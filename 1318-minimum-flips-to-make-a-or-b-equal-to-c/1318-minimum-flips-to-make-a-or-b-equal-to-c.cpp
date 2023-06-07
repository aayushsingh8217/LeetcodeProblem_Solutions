class Solution {
public:
    int minFlips(int a, int b, int c) {
  int flips = 0;
    //int mask = 1;

     for(int i = 0; (1 << i) <= max(max(a, b), c); i++)
     {
            int bit = 1 << i;
            int a_bit = a & bit ? 1 : 0;
            int b_bit = b & bit ? 1 : 0;
            int c_bit = c & bit ? 1 : 0;
            if(!(a_bit | b_bit) && c_bit)
            {
                flips++;
            }
            else if((a_bit & b_bit) && !c_bit)
            {
                flips+=2;
            }else if((a_bit ^ b_bit) && !c_bit)
            {
                flips++;
            }
        }
        
        return flips;
    }
};