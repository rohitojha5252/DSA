
class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(102, vector<int>(2, -1));
    int func(int i, int free, vector<int>&nums){
        int n = nums.size();
        if(i==n)return 0;
        if(dp[i][free] != -1){
            return dp[i][free];
        }
        if(free == 0){
            return dp[i][free] = func(i+1, 1, nums);
        }
        int taken = nums[i]+func(i+1, 0, nums);
        int skip = func(i+1, 1, nums);

        return dp[i][free] = max(taken, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));

        return func(0, 1, nums);
    }
};