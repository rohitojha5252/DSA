class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // vector<vector<int>> adj(n);
        unordered_map<int, int>mp;
        int cnt = 0;
        mp[nums[0]] = 0;

        for(int i = 1; i < n; i++){
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                mp[nums[i]] = cnt;
            }
            else{
                cnt++;
                mp[nums[i]] = cnt;
            }
        }
        vector<bool>ans;

        for(int i=0; i<queries.size(); i++){
            if(mp[nums[queries[i][0]]] == mp[nums[queries[i][1]]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};