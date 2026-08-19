class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = station.size();
        int m = skill.size();
        vector<vector<int>> place(m, vector<int>(2));
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < m && station[i] == skill[j]) {
                place[j][0] = i;
                j++;
            }
        }
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && station[i] == skill[j]) {
                place[j][1] = i;
                j--;
            }
        }

        int ans = 0;

        for (int i = 0; i < m - 1; i++) {
            ans = max(ans, place[i + 1][1] - place[i][0]);
        }

        return ans;
    }
};