class Solution {
public:
    vector<vector<int>>dp;
    vector<int> prefix;
    int sum(int i, int j){
        return prefix[j + 1] - prefix[i];
    }
    int solve(int i, int j) {
    if (i == j) return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
        for (int k = i; k < j; k++) {
            int left = sum(i, k);
            int right = sum(k+1, j);
            if (left < right) {
                ans = max(ans, left + solve(i, k));
            }
            else if (left > right) {
                ans = max(ans, right + solve(k+1, j));
            }
            else {
                ans = max(ans,
                    left + max(solve(i, k), solve(k+1,j))
                );
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        if(stoneValue.size() == 1)return 0;
        dp.assign(stoneValue.size(), vector<int>(stoneValue.size(), -1));
        
        int n = stoneValue.size();
        prefix.resize(n + 1);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        return solve(0, stoneValue.size()-1);
    }
};