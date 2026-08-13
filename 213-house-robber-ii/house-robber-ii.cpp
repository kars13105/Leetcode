class Solution {
public:
    int solve(vector<int>&nums, int m, int n)
    {
       if (m == n) return nums[m];
        int r=nums[n];
        int l;
        if(nums[n-1]<r) l=r;
        else l=nums[n-1];
        
        for(int i=n-2;i>=m;i--)
        {
            if(nums[i]+r>l) 
            {
                int t=l;                
                l=nums[i]+r;
                r=t;
            }
            else r=l;
        }
        return l;
    }
   
    int rob(vector<int>& nums) {
       int n=nums.size()-1;
        if (n+1 == 0) return 0;
        if (n+1 == 1) return nums[0];
        
        int k= solve(nums, 0, n-1);
        int l= solve(nums, 1, n);
        
        
        
        return max(k,l); 
    }
};