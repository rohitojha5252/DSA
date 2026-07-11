class Solution {
public:
    vector<vector<int>>dp = vector<vector<int>>(101, vector<int>(101,-1));
    int func(int n, int m, int row, int col){
        if(row > n-1 || col>m-1)return 0;
        if(dp[row][col]!= -1)return dp[row][col];
        if(row == n-1 && col == m-1){
            return 1;
        }
        int right = func(n, m, row+1, col);
        int down = func(n, m, row, col+1);

        return dp[row][col] = right+down;
    }
    int uniquePaths(int m, int n) {
        return func(m,n,0,0);
    }
};