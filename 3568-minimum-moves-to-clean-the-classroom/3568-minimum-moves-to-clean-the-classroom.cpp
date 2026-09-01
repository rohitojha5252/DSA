class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int starti = -1, startj = -1;
        int totall = 0;

        // Give every L an index
        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    starti = i;
                    startj = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = totall++;
                }
            }
        }

        int fullMask = (1 << totall) - 1;

        // {row, col, remaining_energy, mask}
        queue<array<int, 4>> q;

        q.push({starti, startj, energy, 0});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << totall, false)
                )
            )
        );

        vis[starti][startj][energy][0] = true;

        int dist = 0;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return dist;

                // Can't move anymore
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        int k = id[nx][ny];
                        nmask |= (1 << k);
                    }
                    if(classroom[nx][ny] == 'R'){
                        ne = energy;
                    }

                    // If this state is new
                    if (!vis[nx][ny][ne][nmask]) {
                        vis[nx][ny][ne][nmask] = true;
                        q.push({nx, ny, ne, nmask});
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};