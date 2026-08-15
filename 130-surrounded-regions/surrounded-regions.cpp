class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, -1));
        queue<pair<int, int>>q;

        for(int i=0;i<m;i++)
        {
            if(board[i][0] == 'O')
            {
                vis[i][0] = 1;
                q.push({i,0});
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1] == 'O')
            {
                vis[i][n-1] = 1;
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i] == 'O')
            {
                vis[0][i] = 1;
                q.push({0,i});
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[m-1][i] == 'O')
            {
                vis[m-1][i] = 1;
                q.push({m-1,i});
            }
        }
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r+1<m && board[r+1][c] == 'O' && vis[r+1][c] == -1)
            {
                vis[r+1][c] =1;
                q.push({r+1, c});
            }
            if(r-1>=0 && board[r-1][c] == 'O' && vis[r-1][c] == -1)
            {
                vis[r-1][c] =1;
                q.push({r-1, c});
            }
            if(c+1<n && board[r][c+1] == 'O' && vis[r][c+1] == -1)
            {
                vis[r][c+1] =1;
                q.push({r, c+1});
            }
            if(c-1>=0 && board[r][c-1] == 'O' && vis[r][c-1] == -1)
            {
                vis[r][c-1] =1;
                q.push({r, c-1});
            }
        }

        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(vis[i][j] == -1)
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;


    }
};