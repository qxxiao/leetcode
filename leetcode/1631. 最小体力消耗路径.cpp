#include <queue>
#include <utility>
#include <vector>
using namespace std;
using Tuple = tuple<int, int, int>;  // or PII
class Solution {
    int dist[101][101];
    bool st[101][101];

   public:
    int minimumEffortPath(vector<vector<int>> &heights) {
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

            if (st[x][y]) continue;
            st[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || st[xx][yy]) continue;
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

// 解
// 并查集模板
// class UnionFind
// {
// public:
// 	vector<int> parent;
// 	vector<int> size;
// 	int n;
// 	// 当前连通分量数目
// 	int setCount;

// public:
// 	UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1)
// 	{
// 		iota(parent.begin(), parent.end(), 0);
// 	}

// 	int findset(int x)
// 	{
// 		return parent[x] == x ? x : parent[x] = findset(parent[x]);
// 	}

// 	bool unite(int x, int y)
// 	{
// 		x = findset(x);
// 		y = findset(y);
// 		if (x == y)
// 		{
// 			return false;
// 		}
// 		if (size[x] < size[y])
// 		{
// 			swap(x, y);
// 		}
// 		parent[y] = x;
// 		size[x] += size[y];
// 		--setCount;
// 		return true;
// 	}

// 	bool connected(int x, int y)
// 	{
// 		x = findset(x);
// 		y = findset(y);
// 		return x == y;
// 	}
// };

// class Solution
// {
// public:
// 	int minimumEffortPath(vector<vector<int>> &heights)
// 	{
// 		int m = heights.size();
// 		int n = heights[0].size();
// 		vector<tuple<int, int, int>> edges;
// 		for (int i = 0; i < m; ++i)
// 		{
// 			for (int j = 0; j < n; ++j)
// 			{
// 				int id = i * n + j;
// 				if (i > 0)
// 				{
// 					edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
// 				}
// 				if (j > 0)
// 				{
// 					edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
// 				}
// 			}
// 		}
// 		sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2)
// 			 {
// 				 auto &&[x1, y1, v1] = e1;
// 				 auto &&[x2, y2, v2] = e2;
// 				 return v1 < v2;
// 			 });

// 		UnionFind uf(m * n);
// 		int ans = 0;
// 		for (const auto [x, y, v] : edges)
// 		{
// 			uf.unite(x, y);
// 			if (uf.connected(0, m * n - 1))
// 			{
// 				ans = v;
// 				break;
// 			}
// 		}
// 		return ans;
// 	}
// };