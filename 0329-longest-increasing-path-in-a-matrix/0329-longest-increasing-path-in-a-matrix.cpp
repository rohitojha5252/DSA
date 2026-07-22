class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    int func(vector<vector<int>>& matrix, int i, int j, int prev){
        if(i==n || i<0)return 0;
        if(j==m || j<0)return 0;
        if(matrix[i][j] <= prev)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int left = func(matrix, i-1, j, matrix[i][j]);
        int right = func(matrix, i+1, j, matrix[i][j]);
        int down = func(matrix, i, j+1, matrix[i][j]);
        int up = func(matrix, i, j-1, matrix[i][j]);

        return dp[i][j] = 1+ max({left, right, down, up});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n, vector<int>(m, -1));
        int val = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                val = max(val, func(matrix, i, j, -1));
            }
        }
        return val;
    }
};