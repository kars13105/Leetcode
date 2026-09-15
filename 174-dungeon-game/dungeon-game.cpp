class Solution {
public:
    
    int f(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        if(i == m-1&&j == n-1) return max(1, 1 - dungeon[i][j]);
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int right=INT_MAX;
        int down= INT_MAX;
        if(j+1 <n) right = f(dungeon, i, j+1, dp);
        if(i+1 <m) down = f(dungeon, i+1, j, dp);

        return  dp[i][j] = max(1,min(right, down)-dungeon[i][j]);
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>>dp(m, vector<int>(n+1, INT_MAX));
        return f(dungeon, 0, 0, dp);
    }
};