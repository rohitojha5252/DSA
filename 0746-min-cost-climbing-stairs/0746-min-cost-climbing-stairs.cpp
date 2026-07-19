class Solution {
public:
    vector<int>dp;
    int func(vector<int>& cost, int i, int total){
        int n = cost.size();
        if(i >= n)return 0;

        if(dp[i] != -1)return dp[i];

        int c1 = cost[i] + func(cost, i+1, total);
        int c2 = cost[i] + func(cost, i+2, total);

        return dp[i] = min(c1, c2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size()+1, -1);
        int total = 0;
        int s1 = func(cost, 0, total);
        int s2 = func(cost, 1, total); 
        return min(s1, s2);
    }
};