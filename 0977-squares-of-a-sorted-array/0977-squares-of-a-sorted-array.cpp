class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=-1, j=-1;
        int ind = 0,pind = 0;
        if(nums[0]<0){
            while(ind<nums.size() && nums[ind]<0){
                i = ind;
                ind++;
            }
            pind = i+1;
            j = pind;
        }
        if(j==nums.size()){
            reverse(nums.begin(), nums.end());
            for(int ind = 0; ind<nums.size(); ind++){
                nums[ind] = nums[ind]* nums[ind];
            }
            return nums;
        }
        if(i==-1){
            for(int ind = 0; ind<nums.size(); ind++){
                nums[ind] = nums[ind]* nums[ind];
            }
            return nums;
        }
        vector<int>ans;
        while(i>=0 && j<nums.size()){
            if(abs(nums[i])>=nums[j]){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else if(abs(nums[i])<nums[j]){
                ans.push_back(nums[i]* nums[i]);
                i--;
            }
        }
        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        return ans;
    }
};