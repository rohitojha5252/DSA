class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1)return s;
        int n = s.size();
        string s2 = "";
        for(int i=0; i<n/2; i++){
            s2+=s[i];
        }
        sort(s2.begin(), s2.end());
        char oddplace = s[(n/2)];
        s = "";
        s+=s2;
        if(n%2 == 1) s+=oddplace;
        reverse(s2.begin(), s2.end());
        s+=s2;
        return s;
    }
};