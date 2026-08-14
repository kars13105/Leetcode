class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];

        int left, up;
        
        left= f(i, j-1, grid,dp);
        up= f(i-1, j, grid,dp);
        int best = min(left, up);
        if (best == INT_MAX) return INT_MAX;

        return dp[i][j]=grid[i][j] + best;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m, n;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return f(m-1, n-1, grid,dp);

    }
};