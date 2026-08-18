class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int>mpp;
        int m= INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
            m = max(m, nums[i]);

        }
        if(k == 1)
        {
            int ans = -1;
            for(auto it : mpp)
            {
                if(it.second == 1) ans = max(ans, it.first);
            }

            return ans;
        }
        if (k == nums.size()) return m;
        else
        {
            if(mpp[nums[0]] == 1 && mpp[nums[nums.size()-1]]==1)
            {
                return max(nums[0], nums[nums.size()-1]);
            }
            else if(mpp[nums[0]] == 1) return nums[0];
            else if(mpp[nums[nums.size()-1]] == 1) return nums[nums.size()-1];
            else return -1;
        }
        
    }
};