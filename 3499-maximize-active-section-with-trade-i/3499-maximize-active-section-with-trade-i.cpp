class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt0 = 0, cnt1 = 0, next0 = 0;
        int maxcnt = 0;
        int i=0;
        while(i<n && s[i] == '0'){
            i++;
            cnt0++;
        }
        for(i; i<n; i++){
            next0 = 0;
            while(i<n && s[i] == '1'){
                i++;
                cnt1++;
            }
            while(i<n  && s[i] == '0'){
                next0++;
                i++;
            }
            if(i<n)cnt1++;
            if(cnt0 > 0 && next0 >0)maxcnt = max(maxcnt, cnt0+next0);
            cnt0 = next0;
        }
        return maxcnt+cnt1;
    }
};