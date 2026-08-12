class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int f = 0;
        int i =0, j=0;
        int n = nums.size();

        while(j<n)
        {
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k)
            {
                mpp[nums[i]]--;
                i++;
            }
            f=max(f, j-i+1);
            j++;
        }
        return f;


    }
};