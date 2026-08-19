class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        int maxval = *max_element(lights.begin(), lights.end());
        int pen = 0;
        for(int i=0; i<n; i++){
            int r = arrivalTime[i]%period;
            cout<<r<<endl;
            if(r>=maxval){
                pen=max(pen, period-r);
            }
        }
        return pen;
    }
};