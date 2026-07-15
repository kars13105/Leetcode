class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[0];
        // bool f = false;
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]==m) return true;
            else m = nums[i];
        }
        return false;
    }
};