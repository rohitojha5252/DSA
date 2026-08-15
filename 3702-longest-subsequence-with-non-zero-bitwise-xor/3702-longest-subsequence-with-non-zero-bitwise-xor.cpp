class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        if(n==1 && nums[0] == 0)return 0;
        if(n==1)return 1;
        int cnt0 = 0;
        int val = nums[0];
        if(val == 0)cnt0++;
        for(int i=1; i<n-1; i++){
            val ^= nums[i];
            if(nums[i] == 0)cnt0++;
        }
        // cout<<val<<endl;
        int val2 = val^nums[n-1];
        if(nums[n-1] == 0)cnt0++;
        if(cnt0 == n)return 0;
        if(val2 == 0)return n-1;
        return n;

    }
};