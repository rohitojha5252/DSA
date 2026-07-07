class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        long long mul = 0;
        int time = 0;

        while(n>0){
            num = n % 10;
            n /= 10;
            if(num != 0){
                sum += num;
                mul += num * pow(10, time);
                time++;
            }
        }
        return mul*sum;
    }
};