class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int l = INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            unordered_map<int, int>mpp;
            int lo = 0;
            for(int j=i;j<s.size();j++)
            {
                mpp[s[j]]++;
                if(mpp[s[j]]<=2) lo++;
                else break;
            }
            l = max(l, lo);
        }
        return l;
    }
};