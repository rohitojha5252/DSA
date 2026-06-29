class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int>mp;
        int n = word.size();
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=i; j<n; j++){
                s+=word[j];
                mp[s]++;
            }
        }
        
        int ans = 0;

        for(auto &x:patterns){
            if(mp.find(x)!=mp.end())ans++;
        }

        return ans;
    }
};