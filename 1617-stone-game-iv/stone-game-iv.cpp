class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n==1) return true;
        vector<int>dp(n+1, 0);
        for(int i =0;i<=n;i++)
        {
            if(dp[i] == 0)
            {
                for(int j = 1;i+j*j<=n;j++)
                {
                    dp[i+j*j] = 1;
                }
                if(dp[n] == 1) return true;
            }
        }
        return false;
    }
};