// https://www.acwing.com/problem/content/758/

#include <iostream>

using namespace std;

int m, n;
int res[100][100];

int main()
{
    cin >> n >> m;

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    for (int x = 0, y = 0, k = 1, d = 0; k <= m * n; k++)
    {
        res[x][y] = k; // 当前是可行的位置
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m || res[a][b])
        { // 下一个可行的位置
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}