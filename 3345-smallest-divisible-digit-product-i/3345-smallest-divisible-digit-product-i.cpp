class Solution {
public:
    int smallestNumber(int n, int t) {
        
        bool check = false;
        int temp = n;
        while(temp<=100){
            int val = temp;
            int mul = 1;
            while(val!=0){
                mul *= val%10;
                val /= 10;
            }
            if(mul % t == 0)return temp;
            temp++;
        }
        return temp;
    }
};