class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int total = 0;
        int cnt = 0;
        int i = 0;
        int j = n-1;

        while(i<=j){
            if(tokens[i] <= power){
                cnt++;
                power -= tokens[i];
                i++;
            }
            else if(cnt > 0){
                power += tokens[j];
                total = max(total, cnt);
                cnt--;
                j--;
            }
            else{
                break;
            }
            // cout<<power<<endl;
        }
        total = max(total, cnt);
        return total;
    }
};