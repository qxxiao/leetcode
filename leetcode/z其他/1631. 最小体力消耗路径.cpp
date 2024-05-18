#include <queue>
#include <utility>
#include <vector>
using namespace std;
using Tuple = tuple<int, int, int>; // or PII
class Solution {
    int dist[101][101];
    bool st[101][101];

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);
        priority_queue<Tuple, vector<Tuple>, greater<Tuple>> heap;
        dist[0][0] = 0;
        heap.push({0, 0, 0});

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while (!heap.empty()) {
            Tuple t = heap.top();
            heap.pop();
            auto [d, x, y] = t;

            if (st[x][y])
                continue;
            st[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || st[xx][yy])
                    continue;
                int v = max(dist[x][y], abs(heights[xx][yy] - heights[x][y]));
                if (dist[xx][yy] > v) {
                    dist[xx][yy] = v;
                    heap.push({v, xx, yy});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
