class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>pcd(nums.size());
        int mx = 0;
        for(int i =0;i<nums.size();i++)
        {
            mx= max(mx, nums[i]);
            pcd[i]=gcd(nums[i], mx);
        }
        sort(pcd.begin(), pcd.end());
        long long sum = 0;
        int l =0;
        int r = nums.size()-1;
        while(l<r)
        {
            sum+=gcd(pcd[l], pcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};