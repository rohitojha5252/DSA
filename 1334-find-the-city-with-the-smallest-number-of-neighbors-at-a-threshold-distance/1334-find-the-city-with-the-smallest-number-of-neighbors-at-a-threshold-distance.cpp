class Solution {
public:
    int check(int source,int thre, int n, vector<vector<pair<int,int> >> &g){
        int totalc = 0;

        // vector<int>vis(101));
        vector<int>dist(n,INT_MAX);
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, source});

        while(!pq.empty()){
            int distleft = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(distleft > dist[node])
                continue;

            for(auto &x:g[node]){
                int newnode = x.first;
                int wt = x.second;

                if(dist[node]+wt >= dist[newnode])continue;

                if(distleft + wt <= thre ){
                    pq.push({distleft + wt, newnode});
                    dist[newnode] = distleft+wt;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(i != source && dist[i] <= thre)
            cnt++;
        }

        return cnt;
        
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int> >>g(101);

        for(auto &x: edges){
            int f = x[0];
            int t = x[1];
            int cost = x[2];

            g[f].push_back({t, cost});
            g[t].push_back({f, cost});
        }
        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++){
            int cnt = check(i, distanceThreshold, n, g);
            if(cnt <= mini){
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};