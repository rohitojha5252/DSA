class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int bigi = 0;
        int smalli = 0;

        int smallele = *min_element(nums.begin(), nums.end());
        int bigele = *max_element(nums.begin(), nums.end());
        int first = 0;

        for(int i=0; i<n; i++){
            if(smallele == nums[i]){
                if(first == 0){
                    smalli = i+1;
                    first = 1;
                }
                else{
                    bigi = i+1;
                }
                
            }
            if(bigele == nums[i]){
                if(first == 0){
                    smalli = i+1;
                    first = 1;
                }
                else{
                    bigi = i+1;
                }
            }
        }
        int firstoption = min(smalli, n-smalli+1);
        int secondoption = min(bigi, n-bigi+1);

        smallele = 0;
        smallele += firstoption;
        smallele += min(secondoption, abs(firstoption-bigi));

        bigele = 0;
        bigele += secondoption;
        bigele += min(firstoption, abs(bigi - smalli));

        return min({smallele, bigele});
    }
};