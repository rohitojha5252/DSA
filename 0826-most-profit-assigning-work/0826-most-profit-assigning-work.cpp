class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        int n = difficulty.size();
        vector<pair<int ,int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {difficulty[i], profit[i]};
        }
        sort(vec.begin(), vec.end());
        int m = worker.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int prof = 0;

        while(i<m && j<n){
            int val = worker[i];
            int diff = vec[j].first;
            if(val >= vec[j].first){
                while(j<n && val>=vec[j].first){
                    prof = max(prof, vec[j].second);
                    j++;
                }
            }
            ans+=prof;
            i++;
        }

        if(i<m){
            ans+=prof*(m-i);
        }

        
        return ans;
    }
};