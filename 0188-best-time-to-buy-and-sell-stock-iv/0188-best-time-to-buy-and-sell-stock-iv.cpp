class Solution {
public:
    vector<vector<vector<int>>> dp;
    int func(vector<int> &prices, int i, int k, int cnt){
        int n = prices.size();
        if(i==n)return 0;
        if(cnt == 0)return 0;
        if(dp[i][k][cnt] != -1)return dp[i][k][cnt];

        if(k==1 && cnt>0){//buy
            int c1 = func(prices, i+1, k-1, cnt) - prices[i];
            int c2 = func(prices, i+1, k, cnt);
            return dp[i][k][cnt] = max(c1, c2);
        }
        else if(cnt > 0){
            int c1 = func(prices, i+1, k, cnt);
            int c2 = func(prices, i+1, k+1, cnt-1) + prices[i];
            return dp[i][k][cnt] = max(c1, c2);
        }
        return dp[i][k][cnt] = 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.assign(prices.size()+1, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(prices, 0, 1, k);
    }
};