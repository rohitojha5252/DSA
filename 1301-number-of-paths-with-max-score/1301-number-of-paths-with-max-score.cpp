class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );

        dp[n-1][n-1][0] = 0;
        dp[n-1][n-1][1] = 1;

        for(int i=n-1;i>=0;i--){

            for(int j=n-1;j>=0;j--){

                if(i==n-1 && j==n-1) continue;

                if(board[i][j]=='X') continue;

                int best = -1;
                long long ways = 0;

                // down
                if(i+1<n && dp[i+1][j][1]>0)
                    best = max(best, dp[i+1][j][0]);

                // right
                if(j+1<n && dp[i][j+1][1]>0)
                    best = max(best, dp[i][j+1][0]);

                // diagonal
                if(i+1<n && j+1<n && dp[i+1][j+1][1]>0)
                    best = max(best, dp[i+1][j+1][0]);

                if(best==-1) continue;

                if(i+1<n && dp[i+1][j][0]==best)
                    ways = (ways + dp[i+1][j][1])%MOD;

                if(j+1<n && dp[i][j+1][0]==best)
                    ways = (ways + dp[i][j+1][1])%MOD;

                if(i+1<n && j+1<n && dp[i+1][j+1][0]==best)
                    ways = (ways + dp[i+1][j+1][1])%MOD;

                int val = 0;

                if(board[i][j]>='0' && board[i][j]<='9')
                    val = board[i][j]-'0';

                dp[i][j][0] = best + val;
                dp[i][j][1] = ways;
            }
        }

        if(dp[0][0][1]==0)
            return {0,0};

        return {dp[0][0][0], dp[0][0][1]};
    }
};