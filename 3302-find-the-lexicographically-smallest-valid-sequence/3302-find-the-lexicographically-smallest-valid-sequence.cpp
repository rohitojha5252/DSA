class Solution {
public:
    void push(string word1, string word2, int i, int j, vector<int>&ans){
        int n = word1.size();
        while(i<n){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            i++;
        }
    }
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        vector<int>dp(n,0);
        int i = word1.size()-1;
        int j = word2.size()-1;
        int cnt = 0;
        while(i>=0){
            if(j>0 && word1[i] == word2[j]){
                cnt++;
                j--;
            }
            dp[i] = cnt;
            i--;
        }
        i = 0;
        j = 0;
        vector<int>ans;
        while(i<n){
            if(word1[i] != word2[j]){
                if(i+1<n && dp[i+1] >= word2.size()-(j+1)){
                    ans.push_back(i);
                    push(word1, word2, i+1, j+1, ans);
                    break;
                }
            }
            else{
                ans.push_back(i);
                j++;
            }
            i++;
        }
        if(ans.size() != word2.size())return {};
        return ans;
    }
};