class Solution {
public:
    void dfs(int vertex,vector<vector<pair<int,int> >>&g,int &mini, vector<int>&vis ){
        vis[vertex] = 1;

        for(auto &child:g[vertex]){
            mini = min(mini, child.second);
            if(vis[child.first])continue;
            dfs(child.first, g, mini, vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int> >>g(n+1);
        vector<int>vis(n+1,0);

        for(auto &r:roads){
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }

        int mini = INT_MAX;

        dfs(1, g, mini,vis);

        return mini;

    }
};