class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0; 
        int j = s.size() - 1;

        // 113–138
        // 145-170

        while(i<j){
            if(isalpha(s[i]) != 0 && isalpha(s[j]) != 0){
                char temp = s[j];
                s[j] = s[i];
                s[i] = temp;
                i++;
                j--;
            }
            else if(isalpha(s[i]) == 0){
                i++;
            }
            else{
                j--;
            }
        }

        return s;
    }
};