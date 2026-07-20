class Solution {
public:
    vector<vector<int>>dp;
    int INTMAX = 1e7;
    int func(vector<int>& nums, int ind, int val, int target){
        if(ind == nums.size()){
            if(val == target)return 1;
            else return 0;
        }
        if(dp[ind][1000+val] != INTMAX)return dp[ind][1000+val];
        int pos = func(nums, ind+1, val+nums[ind], target);
        int neg = func(nums, ind+1, val-nums[ind], target);

        return dp[ind][1000+val] = pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.assign(nums.size()+1, vector<int>(2002, INTMAX));
        return func(nums, 0, 0, target);
    }
};