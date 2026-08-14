class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        vector<int>vec(26, -1);
        int len = 0;
        int maxlen = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            if(mp[s[i]]>2){
                int startj = j;
                while(mp[s[i]] != 2){
                    mp[s[j]]--;
                    j++;
                }
                len -= (j-startj-1); 
            }
            else{
                len++;
            }
            cout<<len<<endl;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};