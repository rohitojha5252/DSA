class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans;

        int prev = -1000000;
        int next = 0;

        while (next < n && s[next] != c)
            next++;

        for (int i = 0; i < n; i++) {

            if (i > next) {
                prev = next;
                next++;

                while (next < n && s[next] != c)
                    next++;

                if (next == n)
                    next = 1000000;
            }

            ans.push_back(min(i - prev, next - i));
        }

        return ans;
    }
};