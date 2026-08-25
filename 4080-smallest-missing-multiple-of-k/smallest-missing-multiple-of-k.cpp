class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> seen(nums.begin(), nums.end());
        int c = k;
        while(seen.count(c)) 
        {
            c += k;
        }

        return c;
    }
};