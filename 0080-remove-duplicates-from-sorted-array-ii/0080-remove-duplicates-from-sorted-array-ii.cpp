class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int j = 0;
        
        while(j<n){
            int cnt = 1;
            while(j+1 < n && nums[j] == nums[j+1]){
                j += 1;
                cnt += 1;
            }
            int val = min(2, cnt);
            while(val--){
                nums[l] = nums[j];
                l++;
            }
            j+=1;
        }
        return l;
    }
};