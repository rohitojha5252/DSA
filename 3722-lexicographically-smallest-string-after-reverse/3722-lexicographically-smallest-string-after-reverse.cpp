class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();


        string backans = s;
        int backind = 0;
        for(int i=0; i<n; i++){
            string copy = s;
            reverse(copy.begin()+i, copy.end());
            if(backans>copy){
                backans = copy;
                backind = i;
            }
        }

        string frontans = s;
        int frontind = 0;
        for(int i=0; i<n; i++){
            string copy = s;
            reverse(copy.begin(), copy.begin()+i+1);
            if(frontans>copy){
                frontans = copy;
                frontind = i;
            }
        }

        if(frontans > backans){
            reverse(s.begin()+backind, s.end());
            cout<<backind<<endl;
        }
        else{
            reverse(s.begin(), s.begin()+frontind+1);
            cout<<frontind<<endl;
        }
        
        return s;
    }
};