vector< vector< vector<int>>> dp(2000, vector<vector<int>>(2000, vector<int>(2,0)));


class Solution {
    const int mod = 1e9+7;
public:

    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;
        dp[0] = vector<vector<int>>(m,{1,1});

        for(int i=1; i<n; i++){ 
            //dp[i][j][0];
            int psum = 0;
            for(int j=0; j<m; j++){
                dp[i][j][0] = psum;
                psum += dp[i-1][j][1];psum%=mod;
            }

            //dp[i][j][1];
            int ssum = 0;
            for(int j=m-1; j>=0; --j){
                dp[i][j][1] = ssum;
                ssum += dp[i-1][j][0];
                ssum %= mod; 
            }
        
        }

        int ans = 0;

        for(int i=0; i<m; i++){
            ans += dp[n-1][i][0];ans%=mod;
            ans += dp[n-1][i][1];ans%=mod;
        }
        return ans;
    }
};