class Solution {
public:
    bool checkDivisibility(int n) {
       int pro = 1;
       int digsum = 0;
       int totalsum = 0;
       int temp = n;
       while(n!=0){
            int val = n%10;
            digsum += val;
            pro *= val;
            n /= 10;
       } 
       totalsum = digsum + pro;
       if(temp%totalsum == 0)return true;
       return false;
    }
};