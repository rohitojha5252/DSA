class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int next = nums[0];

        for(int i=0; i<nums.size(); i++){
            int val = nums[i];
            while(val != next){
                ans.push_back(next);
                next++;
            }
            next = nums[i]+1;
        }
        return ans;
    }
};