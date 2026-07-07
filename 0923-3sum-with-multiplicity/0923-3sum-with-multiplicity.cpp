class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());

        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum < target) {
                    j++;
                } 
                else if (sum > target) {
                    k--;
                } 
                else {
                    if (arr[j] != arr[k]) {
                        long long leftCount = 1;
                        long long rightCount = 1;

                        while (j + 1 < k && arr[j] == arr[j + 1]) {
                            leftCount++;
                            j++;
                        }

                        while (k - 1 > j && arr[k] == arr[k - 1]) {
                            rightCount++;
                            k--;
                        }

                        ans += leftCount * rightCount;
                        ans %= MOD;

                        j++;
                        k--;
                    }
                    else {
                        long long m = k - j + 1;
                        ans += m * (m - 1) / 2;
                        ans %= MOD;
                        break;
                    }
                }
            }
        }

        return ans % MOD;
    }
};