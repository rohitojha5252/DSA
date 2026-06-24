class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int cnt0 = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                cnt0++;
            }
        }
        int i = n-1;
        int j = n+cnt0-1;

        while(i>=0){
            if(j<n){
                arr[j] = arr[i];
            }
            if(arr[i] == 0){
                arr[i] = 0;
                j--;
                if(j<n){
                    arr[j] = 0;
                }
            }
            i--;
            j--;
        }
    }
};