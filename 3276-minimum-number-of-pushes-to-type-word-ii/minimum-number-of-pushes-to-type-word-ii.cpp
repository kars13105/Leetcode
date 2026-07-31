class Solution {
public:
    int minimumPushes(string word) {
        // unordered_map<char, int>mpp;
        // for(int i=0;i<word.length();i++)
        // {
        //     mpp[word[i]]++;
        // }
        vector<int>v(26,0);
        for(int i =0; i<word.size(); i++)v[word[i]-'a']++;
        sort(v.begin(), v.end(),greater<int>());
        
        int c = 0;
        //int ct =1;

        for(int i =0;i<v.size();i++)
        {
            c += v[i]*((i/8)+1);

        }
        return c;

        
    }
};