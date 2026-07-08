class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxsize = 0;
        int temp = k;
        int cnt1 = 0;

        while(l<n){

            while(r<n){
                if(nums[r] == 1){
                    cnt1++;
                }
                else{
                    if(temp > 0){
                        cnt1++;
                        temp--;
                    }
                    else{
                        break;
                    }
                }
                r++;
            }

            if(temp==0){
                maxsize = max(maxsize, cnt1);
            }
            if(r==n)return max(maxsize,cnt1);
            // cout<<cnt1<<endl;

            if(nums[l] == 1)cnt1--;
            else{
                temp++;
                cnt1--;
            }
            l++;
        }
        maxsize = max(maxsize, cnt1);
        return maxsize;

    }
};