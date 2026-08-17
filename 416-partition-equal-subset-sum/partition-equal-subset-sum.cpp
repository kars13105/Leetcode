class Solution {
public:
    
    bool f(int index, vector<int>& nums, int sum1, int sum2,
           vector<vector<int>>& dp)
    {
        if(sum1 == sum2)
            return true;
        
        if(index < 0)
            return false;

        if(dp[index][sum1] != -1)
            return dp[index][sum1];

        bool nottake = f(index - 1, nums, sum1, sum2, dp);

        bool take = false;

        if(nums[index] <= sum1)
        {
            take = f(index - 1, nums,
                     sum1 - nums[index],
                     sum2 + nums[index],
                     dp);
        }

        return dp[index][sum1] = (take || nottake);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            sum += nums[i];

        if(sum % 2 != 0)
            return false;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return f(n - 1, nums, sum, 0, dp);
    }
};