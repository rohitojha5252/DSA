class Solution {
public:
    vector<vector<int>>dp = vector<vector<int>>(101,vector<int>(101,-1));
    int func(int n, int m, vector<vector<int>>& obstacleGrid, int row, int col){
        if(row == n-1 && col == m-1){
            return 1;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        if(row>n-1 || col >m-1)return 0;
        if(obstacleGrid[row][col] == 1)return 0;

        int down = func(n,m,obstacleGrid, row+1, col);
        int right = func(n, m, obstacleGrid, row, col+1);

        return dp[row][col] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1] == 1)return 0;

        return func(n,m, obstacleGrid, 0, 0);
    }
};