class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedss) {
        
        
        map<int, vector<int>> mp;

        for (auto &v : reservedss) 
        {
            mp[v[0]].push_back(v[1]);
        }
        int ans = (n - mp.size()) * 2;
        for (auto it : mp) 
        {

            bool l = true;    
            bool m = true;  
            bool r = true;   

            for (int s : it.second) {

                if (s>=2&& s<=5) l = false;

                if (s>=4 &&s<=7) m = false;

                if (s>=6 && s<= 9) r = false;
            }

            if (l && r) ans += 2;
            else if (l || m || r) ans += 1;
        }

        return ans;
    }
};