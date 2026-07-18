class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int> &prices, int i, int k){
        int n = prices.size();
        if(i==n)return 0;
        if(k==0)return 0;

        if(dp[i][k] != -1)return dp[i][k];

        if(k==2){//buy
            int c1 = func(prices, i+1, k-1) - prices[i];
            int c2 = func(prices, i+1, k);
            return dp[i][k] = max(c1, c2);
        }
        else{
            int c1 = func(prices, i+1, k);
            int c2 = func(prices, i+1, k+1) + prices[i];
            return dp[i][k] = max(c1, c2);
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size()+1, vector<int>(3,-1));
        return func(prices, 0, 2);
    }
};