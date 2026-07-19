class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        vector<char>vec(27,0);
        stack<char>st;


        for(auto &x : s){
            mp[x]++;
        }
        st.push(s[0]);
        vec[s[0]-'a'] = 1;
        mp[s[0]]--;
        for(int i=1; i<n; i++){
            mp[s[i]]--;
            if(vec[s[i] - 'a'])continue;
            else{
                while(!st.empty() && mp[st.top()] != 0 && st.top() > s[i]){
                    vec[st.top() - 'a'] = 0;
                    st.pop();
                }
            }
            st.push(s[i]);
            vec[s[i] - 'a'] = 1;
        }

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};