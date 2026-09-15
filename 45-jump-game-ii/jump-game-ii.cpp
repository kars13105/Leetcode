class Solution {
public:
    
    int f(vector<int>&nums, int index, vector<int>& dp)
    {
        if(index >= nums.size() - 1) return 0;
        if(dp[index] != -1) return dp[index];
        int mini=INT_MAX;

        for(int i=1;i<=nums[index];i++)
        {
            if(index + i<nums.size())
            {
                int c =f(nums, index + i, dp);
                if(c!=INT_MAX) mini = min(mini, 1 + c);
            }
        }

        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return f(nums, 0,dp);
    }
};