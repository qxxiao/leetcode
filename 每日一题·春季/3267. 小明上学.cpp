//模拟题 csp

#include <iostream>

using namespace std;

int r, y, g;
int n;
int res;

int main()
{
    cin >> r >> y >> g >> n;
    while (n--)
    {
        int k, t;
        cin >> k >> t;
        if (!k)
            res += t;
        else if (k == 1)
            res += t;
        else if (k == 2)
            res += t + r;
    }
    cout << res << endl;
    return 0;
}