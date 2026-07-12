class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>vec = arr;

        // for(int i=0; i<n; i++){
        //     vec.push_back(arr[i]);
        // }
        int n = arr.size();

        sort(vec.begin(), vec.end());

        unordered_map<int ,int>mp;

        int i=1;
        for(auto &x: vec){
            if(mp[x] != 0)continue;
            mp[x] = i;
            i++;
        }
        
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};