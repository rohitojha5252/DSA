class Solution {
public:
    vector<vector<int>>dp;
    int func(vector<int>& nums, int i, int j){
        if(i>j)return 0;
        int val = INT_MIN;
        if(dp[i][j] != -1)return dp[i][j];
        for(int ind = i; ind <= j; ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1]+func(nums, i, ind-1)+func(nums, ind+1, j);
            val = max(val, cost);
        }
        return dp[i][j] = val;
    }
    int maxCoins(vector<int>& nums) {
        dp.assign(nums.size()+1, vector<int>(nums.size()+1, -1));
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return func(nums, 1, n);
    }
};