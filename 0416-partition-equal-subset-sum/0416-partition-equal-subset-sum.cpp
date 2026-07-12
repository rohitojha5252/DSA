class Solution {
public:
    vector<vector<int>>dp;
    bool func(vector<int>&arr, int sum , int i){
        int n = arr.size();
        if(i==n){
            if(sum == 0){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        if(arr[i]>sum){
            return func(arr, sum, i+1);
        }
        
        int c1 = func(arr, sum-arr[i],i+1);
        int c2 = func(arr, sum, i+1);
        
        return dp[i][sum] = c1 || c2;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1)return false;
        dp.assign(n+1, vector<int>(sum+1, -1));
        
        return func(nums, sum/2, 0);
    }
};