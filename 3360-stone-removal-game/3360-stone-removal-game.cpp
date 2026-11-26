class Solution {
public:
    bool canAliceWin(int n) {
        
        int x = n;
        int y = 10;
        int z = 0;
        while(x>0){
            x -= y;
            if(y==0)return false;
            if(x<0)return false;
            y--;
            x-= y;
            if(y==0)return true;
            if(x<0)return true;
            y--;
        }
        return false;
    }
};