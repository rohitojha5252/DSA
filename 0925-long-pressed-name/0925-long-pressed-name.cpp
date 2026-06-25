class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0; int j=0;

        int n = name.size(), m = typed.size();

        char last;

        while(i<n || j<m){
            if(name[i] == typed[j]){
                last = name[i];
                i++;
                j++;
            }
            else if(name[i] != typed[j] && typed[j] == last){
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }

};