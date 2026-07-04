class Solution {
public:
    double check(int n, int start, int end, vector< vector< pair<int, double> >> &g){
        vector<double>probb(n,0.0);
        vector<int>vis(n,0);
        priority_queue<pair<double, int>> pq;
        double ans = 0;

        pq.push({1,start});
        probb[start] = 1.0;

        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;pq.pop();
            if(vis[node])continue;
            vis[node] = 1;

            if(prob < ans)continue;

            if(node == end){
                // ans = max(ans, prob);
                return prob;
            }

            for(auto &child: g[node]){
                double childprob = child.second;
                int childnode = child.first;
                if(prob*childprob < ans)continue;
                if(prob*childprob > probb[childnode]){
                    pq.push({prob*childprob, childnode});
                    probb[childnode] = prob*childprob;
                }
            }
        }
        return ans;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // double ans = 0;
        vector< vector< pair<int, double> >> g(n);
        int i = 0;
        for(auto &e: edges){
            g[e[0]].push_back({e[1],succProb[i]});
            g[e[1]].push_back({e[0],succProb[i]});
            i++;
        }
        double ans = check(n, start_node, end_node, g);

        return ans;
    }


};