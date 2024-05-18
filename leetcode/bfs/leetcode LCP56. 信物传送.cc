// https://leetcode.cn/problems/6UEx57/
// 01bfs / 最短路求解

// 最短路
// 把每个格子看成一个节点，相邻格子之间连边。若出发格的箭头恰好指着这个方向，边的长度就是 0，否则是
// 01bfs
// 类似，从 0 ~ n 步进行遍历

#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

class Solution {
    using PII = pair<int, int>;
    using PIII = pair<int, PII>;

    int n, m;
    vector<string> matrix;
    vector<vector<int>> d;
    vector<vector<bool>> st;
    char dir[4] = {'^', '>', 'v', '<'};

public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {

        n = matrix.size(), m = matrix[0].size();
        this->matrix = matrix;
        d = vector<vector<int>>(n, vector<int>(m, 0x3f3f3f3f));
        st = vector<vector<bool>>(n, vector<bool>(m, false));
        dijkstra(start[0], start[1]);

        return d[end[0]][end[1]];
    }

    void dijkstra(int x, int y) {
        priority_queue<PIII, vector<PIII>, greater<PIII>> q;
        q.push({
            0, {x, y}
        });

        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int i = t.second.first, j = t.second.second;
            if (st[i][j])
                continue;
            // d[i][j] = t.first;
            st[i][j] = true;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k], b = j + dy[k];
                if (a < 0 || a >= n || b < 0 || b >= m)
                    continue;
                int w = matrix[i][j] == dir[k] ? 0 : 1;
                if (d[a][b] > t.first + w) {
                    d[a][b] = t.first + w;
                    q.push({
                        d[a][b], {a, b}
                    });
                }
            }
        }
    }
};

// =====================================================================
// bfs
class Solution2 {
public:
    unordered_map<char, int> hashx = {
        {'^', -1},
        {'v',  1},
        {'<',  0},
        {'>',  0}
    };
    unordered_map<char, int> hashy = {
        {'^',  0},
        {'v',  0},
        {'<', -1},
        {'>',  1}
    };
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {

        n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> f(n, vector<int>(m, -1));
        int x = start[0], y = start[1];
        queue<tuple<int, int, int>> q;
        walk(x, y, 0, q, matrix, f);

        while (f[end[0]][end[1]] == -1) {
            queue<tuple<int, int, int>> t; // 置换队列
            while (!q.empty()) {
                auto tup = q.front();
                q.pop();
                x = get<0>(tup), y = get<1>(tup);
                if (x == end[0] && y == end[1])
                    return f[x][y];
                for (int i = 0; i < 4; i++) {
                    int x1 = x + dx[i], y1 = y + dy[i];
                    if (check(x1, y1) && f[x1][y1] == -1) {
                        walk(x1, y1, get<2>(tup) + 1, t, matrix, f);
                    }
                }
            }
            swap(q, t);
        }
        return f[end[0]][end[1]];
    }

    bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void walk(int x, int y, int d, queue<tuple<int, int, int>>& q, vector<string>& m, vector<vector<int>>& f) {
        f[x][y] = d, q.push({x, y, d});
        while (true) {
            char c = m[x][y];
            x += hashx[c], y += hashy[c];
            if (check(x, y) && f[x][y] == -1) {
                f[x][y] = d;
                q.push({x, y, d});
            }
            else
                return;
        }
    }
};