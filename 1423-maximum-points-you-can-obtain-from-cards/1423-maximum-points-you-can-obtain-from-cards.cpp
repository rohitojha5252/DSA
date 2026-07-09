class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int maxsum = 0;
        int n = cardPoints.size();
        int windowsum = 0;

        for(int i=0; i<n-k; i++){
            windowsum += cardPoints[i];
        }
        int ind = 0;
        maxsum = max(maxsum, sum - windowsum);
        for(int i = n-k; i<n; i++){
            windowsum += cardPoints[i];
            windowsum -= cardPoints[ind];
            maxsum = max(maxsum, sum - windowsum);
            ind++;
        }
        return maxsum;
    }
};