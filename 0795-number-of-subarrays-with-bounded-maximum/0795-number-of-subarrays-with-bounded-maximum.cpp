class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();

        int cnt = 0;
        int ans = 0;
        int maxel = -1;
        int smallrange = 0;
        int last = -1;

        for(int i=0; i<n; i++){
            if(nums[i]<left){
                ans-=1;
                ans -= smallrange;
                cnt++;
                smallrange++;
            }
            else if(nums[i]>=left && nums[i]<=right){
                maxel = max(maxel, nums[i]);
                cnt++;
                smallrange = 0;
            }
            else{
                if(maxel >= left)ans+= ((cnt)*(cnt+1))/2;
                else ans = 0;
                cnt = 0;
                smallrange = 0;
            }
        }
        if(cnt){
            if(cnt%2 == 0)ans+=((cnt)/2) *(cnt+1);
            else ans+= cnt * ((cnt+1)/2);
        }
        return (ans==-1)?0:ans;
    }
};