//单调栈问题

#include <iostream>
#include <stack>
using namespace std;

using LL = long long;

const int N = 100010;
int h[N];
int l[N]; //左边小于h[i]最近位置
int r[N]; //右边小于h[i]最近位置
int n;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    while (cin >> n, n)
    {
        h[0] = h[n + 1] = -1;
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        stack<int> s1, s2;
        s1.push(0);
        s2.push(n + 1);
        for (int i = 1; i <= n; i++)
        {
            while (!s1.empty() && h[s1.top()] >= h[i]) //别写成了if
                s1.pop();
            //绝对有，-1
            l[i] = s1.top();
            s1.push(i);
        }

        for (int i = n; i; i--)
        {
            while (!s2.empty() && h[s2.top()] >= h[i])
                s2.pop();
            r[i] = s2.top();
            s2.push(i);
        }

        LL res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, ((LL)h[i]) * (r[i] - l[i] - 1));
        cout << res << endl;
    }
    return 0;
}