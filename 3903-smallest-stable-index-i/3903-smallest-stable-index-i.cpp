class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minele, maxele;
        int n = nums.size();
        for(int i=0; i<n; i++){
            maxele = *max_element(nums.begin(), nums.begin()+i);
            minele = *min_element(nums.begin()+i, nums.end());
            int diff = maxele - minele;
            if(diff<=k)return i;
        }
        return -1;
    }
};