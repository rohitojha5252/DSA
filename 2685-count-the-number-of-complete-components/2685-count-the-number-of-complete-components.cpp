class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            adj[i].push_back(i);
        }

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>vis(n,0);
        int comp = 0;

        for(int i=0; i<n; i++){
            if(vis[i])continue;
            else{
                vis[i] = 1;
                bool check = true;
                sort(adj[i].begin(), adj[i].end());
                for(auto &x:adj[i]){
                    sort(adj[x].begin(), adj[x].end());
                     if(adj[x] == adj[i]){
                        vis[x] = 1;
                        // break;
                    }
                    else{
                        check = false;
                        break;
                    }
                }
                if(check){
                    comp++;
                }
            }
        }
        return comp;
    }
};