class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;
        while(1)
        {
            int p = 1;
            int x = num;
            while(x>0)
            {
                p*= x%10;
                x=x/10;

            }
            if(p%t == 0) break;
            num++;
        }
        return num;
    }
};