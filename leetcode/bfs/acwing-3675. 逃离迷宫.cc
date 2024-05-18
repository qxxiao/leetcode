// bfs 扩展
// 最小步数定义为转向/转弯的次数

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110, M = N * N * 4;

int n, m, k;
int sx, sy, tx, ty;
char g[N][N];
int dist[N][N][4];
bool st[N][N][4];

struct Node {
    int x, y, z;
} q[M];

int get(int x) {
    return (x + M) % M;
}

bool bfs() {
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        q[tt++] = {sx, sy, i};
        dist[sx][sy][i] = 0;
    }

    while (hh != tt) {
        auto t = q[hh];
        hh = get(hh + 1);

        if (st[t.x][t.y][t.z])
            continue;
        st[t.x][t.y][t.z] = true;

        int distance = dist[t.x][t.y][t.z];
        if (distance > k)
            continue;
        if (t.x == tx && t.y == ty)
            return true;

        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            int w = i != t.z;
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.') {
                if (dist[x][y][i] > distance + w) {
                    dist[x][y][i] = distance + w;
                    if (!w)
                        hh = get(hh - 1), q[hh] = {x, y, i};
                    else
                        q[tt] = {x, y, i}, tt = get(tt + 1);
                }
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> g[i];
        cin >> k >> sy >> sx >> ty >> tx;
        sx--, sy--, tx--, ty--;
        if (bfs())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}