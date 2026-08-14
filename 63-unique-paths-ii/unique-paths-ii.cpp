class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(i==m-1 && j==n-1) return 1;
        if(i>m-1 || j>n-1) return 0;
        int right, down;
        if(dp[i][j] != -1) return dp[i][j];
        if(obstacleGrid[i][j] == 1) return 0;
        right = f(i, j+1, obstacleGrid, dp);
        down = f(i+1, j, obstacleGrid, dp);
        return dp[i][j] = right + down;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return f(0, 0, obstacleGrid, dp);
    }
};