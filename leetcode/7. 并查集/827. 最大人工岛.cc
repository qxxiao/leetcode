#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    vector<int> p, sz;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    int get(int x, int y) {
        return x * n + y;
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();
        for (int i = 0; i < n * n; i++)
            p.push_back(i), sz.push_back(1);

        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = get(i, j);
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                            int b = get(x, y);
                            if (find(a) != find(b)) {
                                sz[find(b)] += sz[find(a)];
                                p[find(a)] = find(b);
                            }
                        }
                    }
                    res = max(res, sz[find(a)]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    map<int, int> hash;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                            int a = get(x, y);
                            hash[find(a)] = sz[find(a)];
                        }
                    }
                    int s = 1;
                    // c++17
                    for (auto [k, v] : hash)
                        s += v;
                    res = max(res, s);
                }
            }
        }
        return res;
    }
};

// int main() {
//     vector<vector<int>> grid = {
//         {1, 0},
//         {0, 1}
//     };
//     Solution s;
//     s.largestIsland(grid);
//     return 0;
// }