class Solution {
public:
    void func(vector<int> &nums, int ind, vector<int>&temp, set<vector<int>>&ans,vector<bool>&already_visited){
        int n = nums.size();
        if(temp.size() == n){
            ans.insert(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(already_visited[i] == 1)continue;
            temp.push_back(nums[i]);
            already_visited[i] = 1;
            func(nums, i, temp, ans, already_visited);
            temp.pop_back();
            already_visited[i] = 0;
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>temp;
        set<vector<int>> ans;
        vector<bool>already_visited(22,false);
        
        func(nums, 0, temp, ans, already_visited);

        vector<vector<int>>ans2;

        while(!ans.empty()){
            auto it = ans.begin();
            ans2.push_back(*it);
            ans.erase(it);
        }
        
        return ans2;
    }
};