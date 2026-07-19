class Solution {
public:
    vector<int>dp;
    int func(vector<int> &nums, int i, int n){
        if(i>=n)return 0;
        if(dp[i] != -1)return dp[i];

        int c2 = func(nums, i+1, n);
        int c1 = nums[i] + func(nums, i+2, n);

        return dp[i] = max(c1, c2);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        dp.assign(nums.size()+1, -1);
       int n = nums.size();
       int c1 = func(nums, 0, n-1);
        dp.assign(nums.size()+1, -1);
       int c2 = func(nums, 1, n); 
       cout<<nums.size()<<endl;

       return max(c1, c2);
    }  
};