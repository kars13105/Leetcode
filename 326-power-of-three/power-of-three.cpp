class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
        if(n==0) return false;
        if(n==1) return true;
        long long k=3;
        while(k<n)
        {
            // if(k==n) return true;
            k*=3;
        }
        if(k==n) return true;
        return false;
    }
};