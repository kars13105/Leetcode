class Solution {
public:
    
    int f(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)

    {
        
        int row = matrix.size();
        int col =matrix[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        int up=0, down=0, left=0, right=0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
        {
            up = f(matrix, i-1, j, dp);
        }
        if(i+1<row && matrix[i+1][j]>matrix[i][j])
        {
            down = f(matrix, i+1, j, dp);
        }
        if(j+1<col && matrix[i][j+1]>matrix[i][j])
        {
            right = f(matrix, i, j+1, dp);
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
        {
            left = f(matrix, i, j-1, dp);
        }
        return dp[i][j]= 1+ max(max(left, right), max(up, down));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        int ans = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                ans = max(ans, f(matrix, i, j, dp));
            }
        }

        return ans;
    }
};