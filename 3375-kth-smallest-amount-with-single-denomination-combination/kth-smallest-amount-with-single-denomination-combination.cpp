class Solution {
public:

    long long check(vector<int>& a, int i, long long l, long long x){
        if(i == a.size()) return 0;
        long long ans = 0;
        for(int j = i; j < a.size(); j++){
        long long g = gcd(l,(long long)a[j]);
        long long nl = l/ g*a[j];

        if(nl > x) continue;

        ans += x / nl;
        ans -= check(a, j+1, nl, x);
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());
        long long l = coins[0];
        long long r = (long long)k * (long long)coins[0];
        long long ans = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long a = check(coins, 0,1LL,mid );
            if(a>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;

    }
};