class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long product = 1;
        int k = n;
        while(n>0)
        {
            int m = n%10;
            sum+=m;
            product*=m;
            n=n/10;
        }
        product = product + sum;
        if(k%product == 0) return true;
        return false;
    }
};