#include <cstring>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
//------------------------------------------
//water[i][j]=max(heightMap[i][j],min(water[i−1][j],water[i+1][j],water[i][j−1],water[i][j+1]))
using Tuple = tuple<int, int, int>;
class Solution
{
	int dist[210][210]; // 接雨水后的最终高度
	bool st[210][210];

public:
	int trapRainWater(vector<vector<int>> &heightMap)
	{
		int n = heightMap.size();
		int m = heightMap[0].size();
		// 所有路径的边权最大值的最小值
		memset(dist, 0x3f, sizeof dist);
		memset(st, false, sizeof st);
		priority_queue<Tuple, vector<Tuple>, greater<Tuple>> heap;

		for (int i = 0; i < n; i++)
		{
			heap.push(make_tuple(heightMap[i][0], i, 0));
			heap.push(make_tuple(heightMap[i][m - 1], i, m - 1));
			st[i][0] = st[i][m - 1] = true; //确定了dist最终的高度
		}

		for (int j = 1; j < m - 1; j++)
		{
			heap.push(make_tuple(heightMap[0][j], 0, j));
			heap.push(make_tuple(heightMap[n - 1][j], n - 1, j));
			st[0][j] = st[n - 1][j] = true;
		}

		int res = 0;
		while (heap.size())
		{
			Tuple t = heap.top();
			heap.pop();
			// int h = get<0>(t);
			auto [h, x, y] = t;

			st[x][y] = true;
			dist[x][y] = h;
			res += h - heightMap[x][y];
			//更新
			int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && !st[xx][yy])
				{
					if (dist[xx][yy] > max(h, heightMap[xx][yy]))
					{
						dist[xx][yy] = max(h, heightMap[xx][yy]);
						heap.push({dist[xx][yy], xx, yy});
					}
				}
			}
		}
		return res;
	}
};

// class Solution {
// public:
//     struct Point { // 定义点的属性数据结构，存储x, y 坐标 和 val值
//         int x;
//         int y;
//         int val;
//     };
//     struct cmp { // 定义比较规则，值按照从小到大的顺序优先队列
//         bool operator()(Point a, const Point b) const {
//             return a.val > b.val;
//         }
//     };
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int m = heightMap.size();
//         int n = heightMap[0].size();
//         priority_queue<Point, vector<Point>, cmp> que; // 定义优先队列
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
//                     que.push({i, j, heightMap[i][j]}); // 存储
//                     visited[i][j] = true; // 添加访问标志，外层全部访问过
//                 }
//             }
//         }
//         int x_[4] = {1, -1, 0, 0}; // 添加上下左右四个方向
//         int y_[4] = {0, 0, 1, -1};
//         int ans = 0;
//         while (!que.empty()) {
//             Point point = que.top();
//             que.pop();
//             for (int i = 0; i < 4; i++) {
//                 int x = x_[i] + point.x;
//                 int y = y_[i] + point.y;
//                 if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
//                     visited[x][y] = true;
//                     if (heightMap[x][y] <= point.val) {
//                         ans += point.val - heightMap[x][y]; // 比point低就可以存储雨水
//                         que.push({x, y, point.val}); // 同时将高度向内层移动
//                     } else {
//                         que.push({x, y, heightMap[x][y]}); // 将高的作为内层的新的判断标准，判断比它低的点
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
