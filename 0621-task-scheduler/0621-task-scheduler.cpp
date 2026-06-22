class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        unordered_map<char, int> freeAt;

        for (char ch : tasks) {
            freq[ch]++;
            freeAt[ch] = 1;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        int time = 1;

        while (!pq.empty()) {

            vector<pair<int, char>> pulled;
            bool executed = false;

            while (!pq.empty()) {

                auto p = pq.top();
                pq.pop();

                int cnt = p.first;
                char task = p.second;

                if (freeAt[task] <= time) {

                    cnt--;

                    freeAt[task] = time + n + 1;

                    if (cnt > 0) {
                        pulled.push_back({cnt, task});
                    }

                    executed = true;
                    break;
                }
                else {
                    pulled.push_back(p);
                }
            }

            for (auto &x : pulled) {
                pq.push(x);
            }

            time++;
        }

        return time - 1;
    }
};