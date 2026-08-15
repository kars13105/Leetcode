
    
    // int f(int i, vector<int>&dp, vector<int>&nums)
    // {
    //     int n = nums.size();
    //     if(i == n-1) return 1;

    //     while(i<n-1)
    //     {
    //         if(nums[i+1]>nums[i])
    //         {
    //             f(i+1)
    //         }
    //     }
    // }

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};