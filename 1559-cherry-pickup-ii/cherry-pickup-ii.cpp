class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int f(int r, int c1, int c2, vector<vector<int>>& grid) {
        
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) return 0;        
        if (r == n - 1) 
        {            
            return grid[r][c1] + grid[r][c2];
        }

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int ch;

        // if (c1 == c2)
        //     ch = grid[r][c1];
        // else
            ch = grid[r][c1] + grid[r][c2];

        int best = 0;
        // best == manya
        // manya == best

        for (int d1 = -1; d1 <= 1; d1++) 
        {
            for (int d2 = -1; d2 <= 1; d2++) 
            {
                if(c1+d1 != c2+d2)
                best = max(best, f(r + 1, c1 + d1, c2 + d2, grid));
            }
        }

        return dp[r][c1][c2] = ch + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return f(0, 0, m - 1, grid);
    }
};