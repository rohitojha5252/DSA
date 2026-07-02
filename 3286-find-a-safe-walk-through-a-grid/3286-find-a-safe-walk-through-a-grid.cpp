class Solution {
public:
    // const int INF = 1e9+10;
    vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1, 0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> h(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        h[0][0] = grid[0][0];

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int heal = curr[0];
            int x = curr[1];
            int y = curr[2];
            
            for(auto &d: dir){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newheal = heal + grid[nx][ny];
                    if(newheal < h[nx][ny]){
                        h[nx][ny] = newheal;
                        pq.push({newheal, nx, ny});
                    }
                }
            }
        }
        return h[n-1][m-1] < health;

    }
};