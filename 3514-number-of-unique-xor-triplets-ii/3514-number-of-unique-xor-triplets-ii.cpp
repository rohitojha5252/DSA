class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>num(2048, 0);
        int n = nums.size();
        int last = 0;
        for(int i=0; i<n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i; j<n; j++){
                num[nums[i] ^ nums[j]] = 1;
            }
            last = nums[i];
        }
        last = 0;
        int ans = 0;
        vector<int>anss(2048, 0);
        for(int k=0; k<n; k++){
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            for(int l=0; l<2048; l++){
               if(num[l])anss[nums[k] ^ l] = 1;
            }
            last = nums[k];
        }

        for(int i=0; i<2048; i++){
            if(anss[i])ans++;
        }
        return ans;
    }
};