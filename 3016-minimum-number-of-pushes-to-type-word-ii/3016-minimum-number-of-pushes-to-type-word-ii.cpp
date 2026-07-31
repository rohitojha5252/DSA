class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            if(a.second != b.second){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<int, int>mp;
        for(auto &x: word){
            mp[x]++;
        }
        vector<pair<int, int>> vec;
        for(auto &x: mp){
            vec.push_back({x.first, x.second});
        }
        sort(vec.begin(), vec.end(), cmp());
        if(vec.size() <= 8)return n;
        int val = 0;
        for(int i=0; i<8; i++){
            val += vec[i].second;
        }
        for(int i=8; i<vec.size(); i++){
            if(i>=24)val+=4*vec[i].second;
            else if(i>=16)val += 3*vec[i].second;
            else val+=2*vec[i].second;
        }
        return val;
    }
};