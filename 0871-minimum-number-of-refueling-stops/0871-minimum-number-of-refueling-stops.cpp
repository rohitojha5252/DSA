class Solution {
public:
    int minRefuelStops(int target, int startfuel, vector<vector<int>>& station) {

        if(startfuel >= target)return 0;

        int n = station.size();

        priority_queue<int> pq;

        int i = 0;

        for(auto &x: station){
            if(startfuel < x[0])break;
            pq.push(x[1]);
            i++;
        }
        
        int ans = 0;
        while(!pq.empty() ){
            startfuel += pq.top();
            ans++;
            pq.pop();
            if(target <= startfuel){
                return ans;
            }
            while(startfuel > 0 && i<n){
                if(startfuel < station[i][0])break;
                pq.push(station[i][1]);
                i++;
            }
        }

        return startfuel >= target ? ans : -1;
    }
};