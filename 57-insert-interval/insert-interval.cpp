class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int>adj[2];
        for(int i =0;i<intervals.size();i++)
        {
            adj[0].push_back(intervals[i][0]);
            adj[1].push_back(intervals[i][1]);
        }
        adj[0].push_back(newInterval[0]);
        adj[1].push_back(newInterval[1]);
        sort(adj[0].begin(), adj[0].end());
        sort(adj[1].begin(), adj[1].end());

        vector<vector<int>>ans;
        int i =0;
        int ind = 0;
        while(i<=intervals.size())
        {
            ind = adj[0][i];
            while(i + 1 <= intervals.size() && adj[1][i]>=adj[0][i+1])
            {
                i++;
            }
            ans.push_back({ind, adj[1][i]});
            i++;
        }
        return ans;
    }
};