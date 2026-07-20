class Solution {
public:
    vector<int>dp;
    int func(string s, int i, string ss){
        int n = s.size();
        if(i>=n && stoi(ss)<=26 && stoi(ss)>0 && ss[0]!='0')return 1;
        if (ss[0] != '0') {
            int num = stoi(ss);
            if(num==0 || num > 26)return 0;
        }
        else return 0;
        if(dp[i] != -1)return dp[i];
        ss = "";
        ss += s[i];
        int one = func(s, i+1, ss);
        int two = 0;
        if(i+1<n){
            ss += s[i+1];
            two = func(s, i+2, ss);
        }
        return dp[i] = one+two;
        
    }
    int numDecodings(string s) {
        dp.assign(s.size()+1 ,-1);
        string ss = "";
        ss += s[0];
        return func(s, 0, ss);        
    }
};