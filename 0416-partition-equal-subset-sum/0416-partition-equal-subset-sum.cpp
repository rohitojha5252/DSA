class Solution {
public:
    int dp[201][20001];
    int func(int ind, int sum, vector<int>& nums){
        if(sum == 0)return true;
        if(ind<0)return false;
        
        if(dp[ind][sum] != -1)return dp[ind][sum];

        bool ispossible = func(ind-1, sum, nums);

        if(sum - nums[ind] >=0)ispossible |= func(ind-1,sum-nums[ind], nums);

        return dp[ind][sum] = ispossible;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0 )return false;

        memset(dp, -1, sizeof(dp));

        return func(nums.size() - 1, sum/2, nums);
    }
};