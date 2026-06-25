class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(),  people.end());

        int i = 0;
        int j = n-1;
        int ans = 0;

        while(i<j){
            cout<<people[i]<<" "<<people[j]<<endl;
            if(people[i]+people[j] <= limit){
                i++;
                j--;
                ans++;
            }
            else{
                j--;
            }
        }
        int final = n - ans;
        return final;
    }
};