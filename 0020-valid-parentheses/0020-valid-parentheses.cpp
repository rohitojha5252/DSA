unordered_map<char,int>symbols={{'(',-1}, {')',1}, {'{',-3}, {'}',3}, {'[',-2},{']',2}};
class Solution {
public:
    bool isValid(string sa) {
        stack<char> s;
        for (char bracket :sa){
            if(symbols[bracket]<0){
                s.push(bracket);
            }else{
                if(s.empty())return false;
                char top = s.top();
                s.pop();
                if(symbols[top]+symbols[bracket]!=0){
                    return false;
                }
            }
        }
        if(s.empty())return true;
        return false;
    }
};