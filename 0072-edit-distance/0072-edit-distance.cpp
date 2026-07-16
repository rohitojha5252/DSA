class Solution {
public:
    vector<vector<int>>dp;
    int func(string word1, string word2, int i, int j){
        int n = word1.size();
        int m = word2.size();

        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }

        if (dp[i][j] != -1)return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = func(word1, word2, i+1, j+1);
        }

        int insert = 1 + func(word1, word2, i, j+1);
        int remove = 1 + func(word1, word2, i+1, j);
        int replace = 1 + func(word1, word2, i+1, j+1);

        return dp[i][j] = min({insert, remove, replace});

    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return func(word1, word2, 0, 0);
    }
};