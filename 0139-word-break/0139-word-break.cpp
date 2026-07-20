class Solution {
public:
    unordered_set<string>st;
    vector<int>dp;
    int n;
    bool solve(int ind, string &s){
        if(ind >= n)return true;
        if(st.find(s) != st.end()){
            return true;
        }
        if(dp[ind] != -1)return dp[ind];
        for(int l=1; ind+l<=n; l++){
            string temp = s.substr(ind, l);
            if(st.find(temp) != st.end() && solve(ind+l, s))return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.assign(s.size()+1, -1);
        for(auto &word: wordDict){
            st.insert(word);
        }
        return solve(0, s);
    }
};