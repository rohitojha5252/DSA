class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        // int n = queries.size();
        vector<bool>ans;

        for(auto &q : queries){

            int i=0, j=0;
            int size = q.size();
            bool check = true;

            while(i<size && j<pattern.size()){
                // cout<<q[i]<<" "<<pattern[j]<<endl;
                if(q[i] == pattern[j]){
                    i++;
                    j++;
                }
                else if(islower(q[i])){
                    i++;
                }
                else{
                   ans.push_back(false);
                   check = false;
                   break; 
                }
            }
            if(i<size && check){
                while(i<size){
                    if(!islower(q[i])){
                        ans.push_back(false);
                        check = false;
                        break;
                    }
                    i++;
                }
            }
            if(j<pattern.size() && check){
                ans.push_back(false);
                check = false;
            }
            if(check)ans.push_back(true);
        }
        return ans;
    }
};