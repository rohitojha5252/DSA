class Solution {
public:
    vector<vector<int>> dp;
    int INF = 1e9+7;
    int func(vector<vector<int>> & triangle,int n,int row, int col){
        if(dp[row][col] != INF)return dp[row][col];
        if(row == n-1)return dp[row][col] = triangle[row][col];
        int sameind = triangle[row][col]+func(triangle, n, row+1,col);
        int nextind = triangle[row][col]+func(triangle, n, row+1, col+1);

        return dp[row][col] = min(sameind, nextind);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        dp.assign(n, vector<int>(n, INF));

        return func(triangle, n, 0, 0);
    }
};