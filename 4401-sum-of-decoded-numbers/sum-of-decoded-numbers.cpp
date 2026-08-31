class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        int MOD = 1e9+7;
        int n = nums.size();
        int ans = 0;
        int l = 0;

        for (int i = 0; i < n; i++) {
            int width = nums[i] % 10;
            long long d = nums[i] / 10;

            string s = to_string(d);
            l = s.length();

            long long p = (long long)pow(10, l - width);

            long long x = d / p;
            long long y = d % p;

            x = x % MOD;

            long long h = 1;
            while(y > 0)
                {
                    if(y%2 != 0)
                    {
                        h = (h * x) % MOD; 
                    }
                    // CRITICAL FIX: You must square the BASE (x), not the accumulator (h)
                    x = (x * x) % MOD; 
                    y /= 2;
                }

            ans = (ans + h) % MOD;
        }

        return ans;
    }
};