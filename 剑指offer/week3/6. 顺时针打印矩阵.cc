// https://www.acwing.com/problem/content/39/

#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {

        vector<int> v;
        int n = matrix.size();
        if (!n)
            return v;
        int m = matrix[0].size();
        if (!m)
            return v;

        bool *st = new bool[m * n]();
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

        int x = 0, y = 0;
        for (int i = 0, d = 0; i < n * m; i++)
        {
            v.push_back(matrix[x][y]);
            st[x * m + y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a * m + b])
            { // 下一个可行的位置
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return v;
    }
};