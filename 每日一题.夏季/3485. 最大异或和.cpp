//美团2021,笔试题
//tag: Trie, 贪心

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 100010;
const int N = 100010 * 31;
int s[M];
int n, m;

int son[N][2], idx = 0, cnt[N];

void insert(int a, int v)
{

    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = (a >> i) & 1;
        if (!son[p][u])
        {
            son[p][u] = ++idx;
        }
        p = son[p][u];
        cnt[p] += v;
    }
}

int query(int a)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = (a >> i) & 1;
        if (cnt[son[p][!u]])
        {
            p = son[p][!u];
            res = res * 2 + 1;
        }
        else
        {
            p = son[p][u];
            res = res * 2;
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] ^= s[i - 1];
    }

    int res = 0;
    insert(s[0], 1); //下面第一次会删除用到

    for (int i = 1; i <= n; i++)
    {

        if (i > m)
            insert(s[i - m - 1], -1); //注意s[i]-s[i-m]是m个数, s[i-m]保留，删除s[i-m-1]
        res = max(res, query(s[i]));
        insert(s[i], 1);
    }
    cout << res << endl;
}
