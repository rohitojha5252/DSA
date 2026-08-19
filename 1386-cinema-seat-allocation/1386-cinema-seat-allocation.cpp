class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int x = 1;
        bool range25 = true;
        bool range59 = true;
        bool range47 = true;
        int val = 0;
        int block;
        for(int i=0; i<reservedSeats.size(); i++){
            if(reservedSeats[i][0] != x){
                if(range25 && range59 && range47){
                    block = 2;
                }
                else if(range25 || range59 || range47){
                    block = 1;
                }
                else{
                    block = 0;
                }
                val+=block;
                x++;
                if(reservedSeats[i][0] != x){
                    while(reservedSeats[i][0] != x){
                        x++;
                        val+=2;
                    }
                }
                range25 = true;
                range59 = true;
                range47 = true;
            }
            if(reservedSeats[i][1]>=2 && reservedSeats[i][1]<=5){
                range25 = false;
            }
            if(reservedSeats[i][1]>=4 && reservedSeats[i][1]<=7){
                range47 = false;
            }
            if(reservedSeats[i][1]>=6 && reservedSeats[i][1]<=9){
                range59 = false;
            }
        }
        if(x<=n){
            if(range25 && range59 && range47){
            block = 2;
            }
            else if(range25 || range59 || range47){
                block = 1;
            }
            else{
                block = 0;
            }
            val+=block;
            x++;
            while(x<=n){
                val+=2;
                x++;
            }
        }
        
        
        return val;
    }
};