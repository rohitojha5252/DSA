class Solution {
public:
    vector<vector<int>>dp;
    bool func(string &s, string &p, int i, int j){
        int n = s.size(), m = p.size();
        if(i<0 && j<0)return true;
        if(i>=0 && j<0)return false;
        if(i<0 && j>=0){
            for(int ii = j; ii>=0; ii--){
                if(p[ii] != '*')return false;
            }
            return true;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = func(s, p, i-1, j-1);
        }
        if(p[j] == '*'){
            return dp[i][j] = func(s, p, i, j-1) || func(s, p, i-1, j);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        dp.assign(n, vector<int>(m, -1));
        return func(s, p, n-1, m-1);
    }
};