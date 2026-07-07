class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        int maxsize = 0;

        sort(stones.begin(), stones.end());
        int l = 0;
        for(int r = 0; r < n; r++) {
        
            while(stones[r] - stones[l] + 1 > n)
                l++;

            maxsize = max(maxsize, r - l + 1);
        }
        int minisize = 0;

        if ((stones[n-2] - stones[0] == n - 2 &&
             stones[n-1] - stones[n-2] > 2) ||

            (stones[n-1] - stones[1] == n - 2 &&
             stones[1] - stones[0] > 2))
        {
            minisize = 2;
        }
        else{
            minisize = n-maxsize;
        }

        maxsize = 0;

        int fixleft = stones[n-1] - stones[1] - (n-2);
        int fixright = stones[n-2] - stones[0] - (n-2);

        maxsize = max(fixleft, fixright);
        return {minisize, maxsize};
           
    }
};