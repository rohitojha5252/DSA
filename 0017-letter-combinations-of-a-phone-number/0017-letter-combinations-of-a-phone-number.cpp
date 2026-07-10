
class Solution {
public:
    void func(string &s, int n, int ind, string &diary, vector<string>& res, unordered_map<char, string> &f){
        if(ind == n){
            res.push_back(diary);
            return;
        }
        string choice = f[s[ind]];
        for(int j=0; j<choice.size(); j++){
            diary.push_back(choice[j]);
            func(s, n, ind+1, diary, res,f);
            diary.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";
       
        int n = digits.size();
        int ind = 0;
        string diary = "";
        vector<string>ans;
        func(digits, n, ind, diary, ans,f);

        return ans;

    }
};