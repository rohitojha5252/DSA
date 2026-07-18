class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());

        int g = gcd(s, b);

        return g;
    }
};