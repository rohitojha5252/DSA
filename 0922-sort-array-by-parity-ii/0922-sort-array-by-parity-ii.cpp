class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        while(i<n && j<n){
            if(i%2 == 0){
                if(nums[i]%2 == 0){
                    i++;
                    j++;
                }
                else if (nums[j]%2 == 0){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                }
                else{
                    j++;
                }
            }
            else{
                if(nums[i]%2 == 1){
                    i++;
                    j++;
                }
                else if (nums[j]%2 == 1){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                }
                else{
                    j++;
                }
            }
        }
        return nums;
    }
};