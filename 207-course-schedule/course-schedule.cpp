class Solution {
public:
    
    bool dfs(int n, vector<int>& vis,vector<int>& pathvis,vector<int> adj[])
    {
        vis[n] = 1;
        pathvis[n] = 1;
        
        for(auto it : adj[n])
        {
            if(vis[it] == 0)
            {
                
                if(dfs(it, vis, pathvis, adj)) return true;
            }
            else if (pathvis[it] == 1)
            {
                return true;
            }
        }
        pathvis[n] = 0;
        return false;


    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i, vis, pathvis, adj))
                    return false;
            }
        }
        return true;
    }
};