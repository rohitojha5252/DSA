class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        int i = 0;
        int size = 0;

        while(i<n){
            //check small se start ho rha h na a[i];
            while(i+1<n && arr[i+1] <= arr[i]){
                i++;
            }
            //check increasing kb tak hai 
            int inc = 1;
            while(i+1 < n && arr[i+1] > arr[i]){
                inc++;
                i++;
            }
            if(i==n)break;
            
            //check decreasing
            int dec = 0;
            i++;
            while(i<n && arr[i-1]>arr[i]){
                dec++;
                i++;
            }
            cout<<inc<<" "<<dec<<endl;

            if(inc<2 || dec<1 )continue;

            size = max(size, inc+dec);
            i--;
        }
        return size;
    }
};