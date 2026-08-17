class Solution {
public:
    
    int f(vector<int>& stoneValue, int start, int end,
          vector<vector<int>>& dp, vector<int>& prefix)
    {
        if(start == end) return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = 0;

        for(int index = start; index < end; index++)
        {
            int leftSum = prefix[index + 1] - prefix[start];
            int rightSum = prefix[end + 1] - prefix[index + 1];

            if(leftSum < rightSum)
            {
                ans = max(ans, leftSum + f(stoneValue, start, index, dp, prefix));
            }
            else if(leftSum > rightSum)
            {
                ans = max(ans, rightSum + f(stoneValue, index + 1, end, dp, prefix));
            }
            else
            {
                ans = max(ans, leftSum + f(stoneValue, start, index, dp, prefix));
                ans = max(ans, rightSum + f(stoneValue, index + 1, end, dp, prefix));
            }
        }

        return dp[start][end] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(stoneValue, 0, n - 1, dp, prefix);
    }
};