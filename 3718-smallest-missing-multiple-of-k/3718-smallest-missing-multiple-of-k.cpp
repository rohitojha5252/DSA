class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = k;
        for(int i=0; i<n; i++){
            if(nums[i]>start){
                return start;
            }
            else if(nums[i] == start){
                start+=k;
            }
        }
        return start;
    }
};