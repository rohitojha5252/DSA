class Solution {
public:
    vector<vector<long long>>dp;
    long long func(const string &s, const string &t, int i, int j){
        int n = s.size(); 
        int m = t.size();
        if(j==m)return 1;
        if(i==n)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        
        if(s[i] == t[j]){
            long long c1 = func(s, t, i+1, j+1);
            long long c2 = func(s, t, i+1, j);
            return  dp[i][j] = c1+c2;
        }
        return dp[i][j] = func(s,t,i+1,j);

    }
    int numDistinct(string s, string t) {
        dp.assign(s.size()+1, vector<long long>(t.size()+1,-1));
        return  func(s, t, 0, 0);
    }
};