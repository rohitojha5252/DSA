class Solution {
public:
    typedef pair<long long, int> P;
    typedef long long ll;
    bool check(int mid, int n, ll k, vector<vector<pair<int, int>>>& g) {
        vector<ll> d(n, LLONG_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;

        d[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            ll size = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (size > k) {
                return false;
            }
            if (node == n - 1)
                return true;

            if (size > d[node]) {
                continue;
            }

            for (auto& vec : g[node]) {
                int nextnode = vec.first;
                int ncost = vec.second;

                if (ncost < mid)
                    continue;

                if (size + ncost < d[nextnode]) {
                    d[nextnode] = size + ncost;
                    pq.push({size + ncost, nextnode});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,ll k) {
        int n = online.size();

        vector<vector<pair<int, int>>> g(n);

        int l = INT_MAX;
        int r = 0;

        for (auto &x : edges) {
            int u = x[0];
            int v = x[1];
            int cost = x[2];
            if(!online[u] || !online[v]){
                continue;
            }
            g[u].push_back({v, cost});

            l = min(l, cost);
            r = max(r, cost);
        }
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, n, k, g)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};