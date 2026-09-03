class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        int smallesteven = 0;
        int smallestodd = 0;
        for(auto &x: nums1){
            if(x%2 == 0 && smallesteven == 0){
                smallesteven = x;
            }
            if(x%2 != 0 && smallestodd == 0){
                smallestodd = x;
            }
        }
        if(smallestodd == 0)return true;
        if(smallesteven == 0)return true;
        if(smallesteven > smallestodd)return true;
        return false;
    }
};