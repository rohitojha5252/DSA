class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double maxi = -numeric_limits<double>::max();
        double mini = numeric_limits<double>::max();
        long long sum = 0;
        double mean;
        double median;
        double mode;
        bool mi = false;
        int total = 0;
        int ma = INT_MIN;
        // bool ma = false;

        for(int i=0; i<256; i++){
            if(count[i] > 0 && !mi){
                mini = i * 1.0;
                mi = true;
            }
            if(count[i] > 0){
                maxi = i * 1.0;
            }

            sum += 1LL * count[i] * i ;
            total += count[i];

            if(ma < count[i]){
                ma = count[i];
                mode = i * 1.0;
            }
        }

        mean = double(sum) / total;

        if(total%2 == 0){
            int mid = total/2;
            int mid1 = mid+1;

            int i=0;
            bool check = true;
            int cnt = 0;

            while(i<256){
                cnt+=count[i];
                if(cnt>=mid && check){
                    median = i * 1.0; 
                    check = false;
                }
                if(cnt>=mid1){
                    median += i*1.0;
                    break;
                }
                i++;
            }
            median /= 2;
        }
        else{
            int mid = (total/2) + 1;
            int cnt = 0;
            int i = 0;
            while(i<256){
                cnt+=count[i];
                if(cnt>=mid){
                    median = i * 1.0; 
                    break;
                }
                i++;
            }
        }

        return {mini, maxi, mean, median, mode};

    }
};