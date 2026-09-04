class Solution {
public:
    typedef pair<long long, int>P;
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>g(n);
        for(int i=0; i<roads.size(); i++){
            int x,y,wt;
            x = roads[i][0];
            y = roads[i][1];
            wt = roads[i][2];
            g[x].push_back({y, wt});
            g[y].push_back({x, wt});
        }
        vector<long long>dist(n, LLONG_MAX);
        vector<int>ways(n, 0);
        priority_queue<P, vector<P>, greater<P>>pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        int cnt = 0;
        int ans = INT_MAX;

        while(!pq.empty()){
            auto node = pq.top();
            int dis = node.first;
            int parent = node.second;
            pq.pop();
            if(dis > dist[parent])continue;
            for(auto &x: g[parent]){
                int child_v = x.first;
                long long wt = x.second;
                if(dist[child_v] > dist[parent]+wt){
                    dist[child_v] = dist[parent]+wt;
                    ways[child_v] = ways[parent];
                    pq.push({dist[parent]+wt, child_v});
                }
                else if(dist[child_v] == dist[parent]+wt){
                    ways[child_v] = (ways[parent]+ways[child_v])%mod;
                }
            }
        }
        return ways[n-1];
    }
};