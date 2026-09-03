class Solution {
public:
    
    bool evencheck(vector<int>&nums1)
    {
        int mn = INT_MAX;

        for(int i = 0; i < nums1.size(); i++)
        {
            if(nums1[i] % 2 != 0)
                mn = min(mn, nums1[i]);
        }

        
        if(mn == INT_MAX)
            return true;

        for(int i = 0; i < nums1.size(); i++)
        {
            if(nums1[i] % 2 == 0 && nums1[i] < mn)
                return false;
        }

        return true;
    }

    bool oddcheck(vector<int>&nums1)
    {
        int mn = INT_MAX;

        for(int i = 0; i < nums1.size(); i++)
        {
            if(nums1[i] % 2 != 0)
                mn = min(mn, nums1[i]);
        }

        
        if(mn == INT_MAX)
            return true;

        for(int i = 0; i < nums1.size(); i++)
        {
            if(nums1[i] % 2 == 0 && nums1[i] < mn)
                return false;
        }

        return true;
    }
    
    bool uniformArray(vector<int>& nums1) {
        int even = 0;
        int odd = 0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i] % 2 == 0) even++;
            else odd++;
        }
        bool t = false;

        if(odd > even) 
        {
            t = evencheck(nums1);
            if(t== false) t = oddcheck(nums1);
            return t;
        }
        else 
        {
            t = oddcheck(nums1);
            if(t== false) t = evencheck(nums1);
            return t;
        }
        
    }
};