class Solution {
public:
    vector<vector<int>>dp;
    bool func(string s1, string s2, string s3, int i, int j){
        int n = s1.size();
        int m = s2.size();
        if(i+j == s3.size() && i==n && j == m){
            return true;
        }
        if(dp[i][j] != -1)return dp[i][j];
        bool takei = false;
        bool takej = false;
        
        if(i<n && s1[i] == s3[i+j])takei = func(s1, s2, s3, i+1, j);
        if(j<m && s2[j] == s3[i+j])takej = func(s1, s2, s3, i, j+1);
       
        return dp[i][j] = takei || takej;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        dp.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
        return func(s1, s2, s3, 0, 0);
    }
};