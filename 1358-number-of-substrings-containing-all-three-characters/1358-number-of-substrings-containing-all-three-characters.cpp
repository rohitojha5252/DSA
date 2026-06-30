class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ans = 0;
        int cnta = 0,cntb = 0,cntc = 0;

        int i = 0;
        int j = 0;

        while(i<n){
            if(s[i] == 'a')cnta++;
            if(s[i] == 'b')cntb++;
            if(s[i] == 'c')cntc++;
            while(cnta>=1 && cntb>=1 && cntc >=1) {
                ans+= n-i;
                if(s[j] == 'a')cnta--;
                if(s[j] == 'b')cntb--;
                if(s[j] == 'c')cntc--;
                j++;
            }
            i++;
        }
        return ans;
    }
};