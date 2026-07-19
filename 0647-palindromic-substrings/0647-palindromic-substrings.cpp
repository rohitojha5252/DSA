class Solution {
public:
    vector<vector<int>>dp;
    bool check(string &s, int i, int j){
        if(i>j){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = check(s, i+1, j-1);
        }
        return dp[i][j] =  false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        dp.assign(n+1, vector<int>(n+1, -1));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                if(check(s, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};