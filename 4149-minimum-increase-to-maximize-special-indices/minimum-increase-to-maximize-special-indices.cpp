class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        long long ans1 = 0, ans2 = 0;
        int m = 0;
        vector<long long>d1(n, 0);
        vector<long long>d2(n, 0);

       
        for (int i = 1; i < n - 1; i += 2) {
            m = max(nums[i - 1], nums[i + 1]) - nums[i];
            m = max(m + 1, 0);
            ans1 += m;
            d1[i]= ans1;
        }
        if(n%2) return ans1;
     
        for (int i = n - 2; i >= 2; i -= 2) {
            m = max(nums[i - 1], nums[i + 1]) - nums[i];
            m = max(m + 1, 0);
            ans2 += m;
            d2[i] = ans2;
        }

        ans1 = min(ans1, ans2);

        
        for (int i = 2; i < n - 2; i += 2) {
            ans1 = min(ans1, d1[i - 1] + d2[i + 2]);
        }

        return ans1;
    }
};