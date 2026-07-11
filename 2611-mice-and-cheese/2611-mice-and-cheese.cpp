class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<n; i++){
            pq.push({reward1[i] - reward2[i], i});
        }
        int ans = 0;
        while(k--){
            int ind = pq.top().second;
            pq.pop();
            ans += reward1[ind]-reward2[ind];
        }
        for(int i=0; i<n; i++){
            ans+=reward2[i];
        }
        return ans;
    }
};