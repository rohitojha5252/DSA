class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int val = -1;
        int mindis = INT_MAX;
        for(int i=0; i<drones.size(); i++){
            int diss = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(diss<=drones[i][2]){
                if(diss<mindis){
                    mindis = diss;
                    val = i;
                }
            }
        }
        return val;
    }
};