class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mx(n);
        vector<int>mn(n);
        
        int maxx = INT_MIN;
        int minn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxx)
            {
                maxx = nums[i];
            }
            mx[i] = maxx;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<minn)
            {
                minn = nums[i];
            }
            mn[i] = minn;
        }
        bool f = false;
        int score;
        //int minscore = INT_MAX;
        int index;
        for(int i=0;i<n;i++)
        {
            score = mx[i]-mn[i];
            if(score <=k)
            {
                f = true;
                index = i;
                break;
                
            }

        }
        if(f) return index;
        return -1;
    }
};