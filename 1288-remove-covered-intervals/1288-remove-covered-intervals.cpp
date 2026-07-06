struct cmp{
    bool operator()(vector<int> &a, vector<int> &b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        return b[1] < a[1];
    }
};
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),cmp());
        int prevlast = intervals[0][1];
        int cnt = 1;
        for(int i=1; i<intervals.size(); i++){
            int last = intervals[i][1];
            if(last <= prevlast){
                continue;
            }
            prevlast = last;
            cnt++;
        }
        return cnt;
    }
};