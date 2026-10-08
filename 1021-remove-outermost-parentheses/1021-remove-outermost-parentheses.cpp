class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        int n = s.size();
        string ans = "";
        string temp = "";
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(cnt != 0)ans.push_back(s[i]);
                cnt++;
            }
            else if(s[i] == ')'){
                if(cnt == 1){
                    cnt--;
                    continue;
                }
                ans.push_back(s[i]);
                cnt--;
            }
        }
        return ans;
    }
};