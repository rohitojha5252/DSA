class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        map<int, int>mp;

        for(auto &x:nums){
            mp[x]++;
        }

        int num1 = mp[1];
        int maxans = 1;

        
        for(auto &x:mp){
            if(x.first == 1)continue;
            int ans = 0;
            long long cur = x.first;

            while (mp[cur] >= 2) {
                ans += 2;
                if (cur > LLONG_MAX / cur)
                break;
                cur = 1LL * cur * cur;
            }

            if (mp[cur] == 1)
                ans += 1;
            else
                ans -= 1;
            
            maxans = max(maxans, ans);
        }
        // if(num1%2 != 0)num1 = 
        if(num1 > maxans)return (num1%2 != 0)?num1:num1-1;
        return maxans;
    }
};