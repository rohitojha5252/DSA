class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>store;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                store.push_back(grid[i][j]);
            }
        }

        int total = m*n;
        k = k%total;
        int pos = total-k;

        int r=0; int c=0;
        for(int i=pos; i<store.size(); i++){
            grid[r][c] = store[i];
            c++;
            if(c == m){
                c = 0;
                r++;
            }
        }
        for(int i=0; i<pos; i++){
            grid[r][c] = store[i];
            c++;
            if(c == m){
                c = 0;
                r++;
            }
        }
        return grid;
    }
};