class Solution {
public:
    vector<vector<int>>dp;
    int func(string &s, string &s1,int i, int j){
        int n = s.size();
        if(i==n || j==n){
            return 0;
        }
        if(s[i] == s1[j]){
            return dp[i][j] = 1 + func(s, s1, i+1, j+1);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int c1 = func(s, s1, i, j+1);
        int c2 = func(s, s1, i+1, j);

        return dp[i][j] = max(c1, c2);
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.assign(n+1, vector<int>(n+1, -1));

        string s1 = s;
        reverse(s1.begin(), s1.end());

        return n-func(s, s1, 0, 0);
    }
};