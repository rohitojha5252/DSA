class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        long long validpoints = 0;

        unordered_map<int, int>mp;

        mp[0] = 1;

        int cumsum = 0;


        for(int i=0; i<n; i++){
           
            if(nums[i] == target){
                validpoints += mp[cumsum];
                cumsum+=1;
            }
            else{
                cumsum-=1;
                validpoints -= mp[cumsum];
            }
            mp[cumsum] += 1;
            ans += validpoints;
        }
        return ans;
    }
};