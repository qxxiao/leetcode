// https://www.acwing.com/problem/content/description/22/
// 题解： https://www.acwing.com/solution/content/730/

// dfs / bfs
class Solution
{
    bool *st;

public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (!rows || !cols)
            return 0;
        st = new bool[rows * cols]();
        return dfs(threshold, rows, cols, 0, 0);
    }

    bool check(int threshold, int x, int y)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        while (y)
        {
            sum += y % 10;
            y /= 10;
        }
        return sum <= threshold;
    }

    int dfs(int threshold, int rows, int cols, int x, int y)
    {
        int res = 0;

        // 该格子满足要求
        st[x * cols + y] = true;
        res++;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < rows && b >= 0 && b < cols && !st[a * cols + b] && check(threshold, a, b))
            {
                res += dfs(threshold, rows, cols, a, b);
            }
        }
        return res;
    }
};

// bfs
#include <utility>
#include <vector>
#include <queue>

using namespace std;
class Solution2
{
public:
    int get_sum(pair<int, int> p)
    {
        int s = 0;
        while (p.first)
        {
            s += p.first % 10;
            p.first /= 10;
        }
        while (p.second)
        {
            s += p.second % 10;
            p.second /= 10;
        }
        return s;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if (!rows || !cols)
            return 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> st(rows, vector<bool>(cols, false));

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        int res = 0;
        q.push({0, 0});
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            if (st[t.first][t.second] || get_sum(t) > threshold)
                continue;
            res++;
            st[t.first][t.second] = true;
            for (int i = 0; i < 4; i++)
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols)
                    q.push({x, y});
            }
        }

        return res;
    }
};