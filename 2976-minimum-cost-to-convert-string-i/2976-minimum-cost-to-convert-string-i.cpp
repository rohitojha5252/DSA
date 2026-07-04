class Solution {
public:
    typedef pair<long long, int> P;
    const long long INF = 1e18;

    void dijkstra(int src,
                  unordered_map<char, vector<pair<char, int>>> &g,
                  vector<vector<long long>> &allDist) {

        vector<long long> dist(26, INF);
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            char ch = node + 'a';

            for (auto &x : g[ch]) {
                int next = x.first - 'a';
                int wt = x.second;

                if (dist[next] > d + wt) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        allDist[src] = dist;
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        unordered_map<char, vector<pair<char, int>>> g;

        for (int i = 0; i < original.size(); i++) {
            g[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> allDist(26, vector<long long>(26, INF));

        // Run Dijkstra from every character
        for (int i = 0; i < 26; i++) {
            dijkstra(i, g, allDist);
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (allDist[u][v] == INF)
                return -1;

            ans += allDist[u][v];
        }

        return ans;
    }
};