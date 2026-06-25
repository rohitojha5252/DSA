class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;

        for (string &w : words) {
            int i = 0, j = 0;
            bool ok = true;

            while (i < s.size() && j < w.size()) {
                if (s[i] != w[j]) {
                    ok = false;
                    break;
                }

                char c = s[i];

                int cntS = 0;
                while (i < s.size() && s[i] == c) {
                    cntS++;
                    i++;
                }

                int cntW = 0;
                while (j < w.size() && w[j] == c) {
                    cntW++;
                    j++;
                }

                if (cntS < cntW) {
                    ok = false;
                    break;
                }

                if (cntS != cntW && cntS < 3) {
                    ok = false;
                    break;
                }
            }

            if (i != s.size() || j != w.size())
                ok = false;

            if (ok) ans++;
        }

        return ans;
    }
};