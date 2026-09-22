class Solution {
public:
    int reverseDegree(string s) {
       unordered_map<char,int>mp;
        for(int i=0; i<26; i++){
            mp['a'+i] = 26-i;
        }
        int val = 0;
        for(int i=0; i<s.size(); i++){
            val += mp[s[i]] * (i+1);
        }
        return val;
    }
};