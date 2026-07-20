class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>ans(m, vector<int>(n));
        vector<int>mo;
        
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                mo.push_back(grid[i][j]);
            }
        }
        vector<int>no(mo.size());
        for(int i =0;i<mo.size();i++)
        {
            int index = (i+k)%mo.size();
            no[index]=mo[i];
        }
        int ind = 0;
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                ans[i][j]=no[ind];
                ind++;
            }
        }
        return ans;

    }
};