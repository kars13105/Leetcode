class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int c = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == -1 && grid[i][j] == '1') {
                    c++;
                    q.push({i, j});
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        if (r + 1 < m && grid[r + 1][c] == '1' && vis[r + 1][c] == -1) {
                            vis[r + 1][c] = 1;
                            q.push({r + 1, c});
                        }
                        if (r - 1 >= 0 && grid[r - 1][c] == '1' &&
                            vis[r - 1][c] == -1) {
                            vis[r - 1][c] = 1;
                            q.push({r - 1, c});
                        }
                        if (c + 1 < n && grid[r][c + 1] == '1' &&
                            vis[r][c + 1] == -1) {
                            vis[r][c + 1] = 1;
                            q.push({r, c + 1});
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1' &&
                            vis[r][c - 1] == -1) {
                            vis[r][c - 1] = 1;
                            q.push({r, c - 1});
                        }
                    }
                }
            }
        }
        return c;
    }
};