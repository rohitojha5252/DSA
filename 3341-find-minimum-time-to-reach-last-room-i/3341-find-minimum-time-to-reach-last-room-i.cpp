class Solution {
public:
    vector<vector<int>> directions{ {1,0}, {-1,0}, {0,1}, {0,-1}};
    typedef pair<int, pair<int, int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>>result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;

        result[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            int time = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();
            if(i == n-1 && j == m-1){
                return time;
            }
            for(auto &dir:directions){
                int i_ = i+dir[0];
                int j_ = j+dir[1];

                if(i_>=0 && i_<n && j_>=0 && j_<m){
                    int wait = max(moveTime[i_][j_] - time, 0);
                    int addtime = time + wait + 1;
                    if(result[i_][j_]  > addtime){
                        result[i_][j_] = addtime;
                        pq.push({addtime, {i_, j_}});
                    }
                }
            }
        }
        return -1;

    }
};