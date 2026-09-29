class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int n = s.size();
        int maxans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(')st.push(s[i]);
            else if(s[i] == ')')st.pop();
            maxans = max(maxans, (int)st.size());
        }
        return maxans;
    }
};