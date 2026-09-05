class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minele, maxele = INT_MIN;
        int n = nums.size();
        vector<int>vec(n);
        int mini = INT_MAX;
        for(int i=n-1; i>=0; --i){
            mini = min(mini, nums[i]);
            vec[i] = mini;
        }
        for(int i=0; i<n; i++){
            maxele = max(maxele, nums[i]);
            minele = vec[i];
            int diff = maxele - minele;
            if(diff<=k)return i;
        }
        return -1;
    }
};