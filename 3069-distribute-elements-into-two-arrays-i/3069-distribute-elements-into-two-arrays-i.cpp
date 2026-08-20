class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>nums1;
        vector<int>nums2;
        int n = nums.size();
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        for(int i=2; i<n; i++){
            int n1 = nums1.size();
            int n2 = nums2.size();
            if(nums1[n1-1] > nums2[n2-1]){
                nums1.push_back(nums[i]);
            }
            else{
                nums2.push_back(nums[i]);
            }
        }
        int n1 = nums1.size();
        nums.clear();
        cout<<n1<<endl;
        for(int i=0; i<n1; i++){
            nums.push_back(nums1[i]);
        }
        int n2 = nums2.size();
        for(int i=0; i<n2; i++){
            nums.push_back(nums2[i]);
        }
        return nums;
    }
};