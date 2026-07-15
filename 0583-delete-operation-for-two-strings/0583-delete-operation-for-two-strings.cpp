class Solution {
public:
    vector<vector<int>>dp;
    int func(string &s, string &s1,int i, int j){
        int n = s.size();
        int m = s1.size();
        if(i==n || j==m){
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n+1, vector<int>(m+1, -1));
        int len = func(word1, word2, 0, 0);
        return m+n-2*len;   
    }
};