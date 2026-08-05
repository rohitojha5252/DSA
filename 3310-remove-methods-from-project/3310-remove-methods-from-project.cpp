class Solution {
public:
    vector<int>vis;
    void dfs(vector<vector<int>> &adj, int k){
        if(vis[k])return;
        vis[k] = 1;
        for(int i=0; i<adj[k].size(); i++){
            dfs(adj, adj[k][i]);
        }
        return;
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vis.assign(n, 0);
        vector<vector<int>>adj(n);
        unordered_map<int, int>mp;
        int cmp = 1;
        for(int i=0; i<invocations.size(); i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        

        dfs(adj, k);


        // Check if any non-suspicious method calls a suspicious method
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};