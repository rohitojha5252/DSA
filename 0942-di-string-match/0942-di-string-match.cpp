class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>vec(n+1);
        int i=0;
        int val = 0;
        while(i<n){
            if(s[i] == 'I'){
                vec[i] = val;
                val++;
            }
            i++;
        }
        i = 0;
        val = n;
        while(i<n){
            if(s[i] == 'D'){
                vec[i] = val;
                val--;
            }
            i++;
        }
        vec[n] = val;
        return vec;
    }
};