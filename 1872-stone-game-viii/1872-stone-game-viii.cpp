class Solution {
public:
    
    // int solve(vector<int>prefix, int i){
    //     if(i==prefix.size()-1){
    //         return prefix[i];
    //     }
    //     if(t[i] != -1)return t[i];
    //     int take = prefix[i] - solve(prefix, i+1);
    //     int skip = solve(prefix, i+1);
    //     return t[i] = max(take, skip);
    // }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        // memset(t, -1, sizeof(t));
        
        vector<int>prefix(n, 0);
        prefix[0] = stones[0];
        for(int i=1; i<n; i++){
            prefix[i] = stones[i]+prefix[i-1];
        }
        vector<int>t(n,0);
        t[n-1] = prefix[n-1];
        for(int i=n-2; i>=0; --i){
            int take = prefix[i] - t[i+1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }
        return t[1];
    }
};