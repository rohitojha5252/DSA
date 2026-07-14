class Solution {
public:
    vector<vector<int>>dp = vector<vector<int>>(1001, vector<int>(1001, -1));
    int func(string &s1, string &s2, int i, int j){
        int n = s1.size();
        if(i==n || j==n)return 0;
        if(s1[i] == s2[j]){
            return 1 + func(s1, s2, i+1, j+1);
        }
        if(dp[i][j] != -1)return dp[i][j];
        int c1 = func(s1, s2, i, j+1);
        int c2 = func(s1, s2, i+1, j);

        return dp[i][j] = max(c1, c2);
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        return func(s, s1, 0, 0);
    }
};