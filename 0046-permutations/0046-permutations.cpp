class Solution {
public:
    void func(vector<int> &nums, int ind, vector<int>&temp, vector<vector<int>>&ans,vector<bool>&already_visited){
        int n = nums.size();
        if(temp.size() == n){
            ans.push_back(temp);
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>> ans;
        vector<bool>already_visited(22,false);


            func(nums, 0, temp, ans, already_visited);
        

        return ans;
    }
};