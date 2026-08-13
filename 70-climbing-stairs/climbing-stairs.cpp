class Solution {
public:
    /*
    int f(int n, vector<int>&dp)
    {
        //if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        int l= f(n-1, dp);
        int r= f(n-2, dp);

        return dp[n]=l+r;
    }
    */
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        dp[1]=1;
        if(n>1) dp[2]=2;
        for(int i=3; i<=n; i++){
            int l= dp[i-1];
            int r= dp[i-2];
            dp[i]=l+r;
        }
        return dp[n];
    }
};