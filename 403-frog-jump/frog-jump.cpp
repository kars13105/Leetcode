class Solution {
public:
    
    bool f(vector<int>& s, int k, int index, vector<vector<int>>& dp)
    {
        if(index == s.size()-1) return true;

        if(dp[index][k] != -1)
            return dp[index][k];

        bool t1 = false, t2 = false, t3 = false;
        for(int i = index + 1; i < s.size(); i++)
        {
            int dist = s[i] - s[index];

            if(dist == k)
                t1 = f(s, k, i, dp);

            if(dist == k + 1)
                t2 = f(s, k + 1, i, dp);
            if(k - 1 > 0 && dist == k - 1)
                t3 = f(s, k - 1, i, dp);
        }

        return dp[index][k] = t1 || t2 || t3;
    }

    bool canCross(vector<int>& stones) {
        
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        if(stones[1] != 1) return false;

        return f(stones, 1, 1, dp);
    }
};