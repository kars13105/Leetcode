class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);
        for(int i =0; i<word.size(); i++)v[word[i]-'a']++;
        sort(v.begin(), v.end(),greater<int>());
        
        int c = 0;

        for(int i =0;i<v.size();i++)
        {
            c += v[i]*((i/8)+1);
        }
        return c;
    }
};