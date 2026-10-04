class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &s, int ind, int balance) {
        if (balance < 0)
            return false;

        if (ind == s.size())
            return balance == 0;

        if (dp[ind][balance] != -1)
            return dp[ind][balance];

        if (s[ind] == '(') {
            return  dp[ind][balance] = solve(s, ind + 1, balance + 1);
        }
        if (s[ind] == ')') {
            return  dp[ind][balance] = solve(s, ind + 1, balance - 1);
        }
        return  dp[ind][balance] = 
            solve(s, ind + 1, balance + 1) ||
            solve(s, ind + 1, balance - 1) ||
            solve(s, ind + 1, balance);
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n+1, -1));
        return solve(s, 0, 0);
    }
};