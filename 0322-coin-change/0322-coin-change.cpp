class Solution {
public:
    vector<int>dp;
    int func(vector<int> &coins, int left){
        if(left<0){
            return INT_MAX;
        }
        if(left == 0){
            return 0;
        }
        if(dp[left]!= -1)return dp[left];
        int n = coins.size();
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            int x = func(coins, left - coins[i]);
            if(x != INT_MAX)
                ans = min(ans, 1 + x);
        }   
        return dp[left] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1, -1);
        if(amount == 0)return 0;
        func(coins, amount);
        return dp[amount]!=INT_MAX?dp[amount]:-1;
    }
};