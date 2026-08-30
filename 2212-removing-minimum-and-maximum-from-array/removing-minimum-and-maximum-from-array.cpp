class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = 0, maxi = 0;

        for (int i = 0; i < n; i++) 
        {
            if (nums[i] < nums[mini]) mini = i;

            if (nums[i] > nums[maxi]) maxi = i;
        }

        int l = min(mini, maxi);
        int r = max(mini, maxi);

        
        int c1 = r + 1;
        int c2 = n - l;        
        int c3 = (l + 1) + (n - r);

        return min(c1, min(c2, c3));
    }
};