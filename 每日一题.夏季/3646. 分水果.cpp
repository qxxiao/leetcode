#include <iostream>
#include <algorithm>

using namespace std;

int s[7][3] = {
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1},
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int res = 0;
        for (int i = 0; i < 1 << 7; i++)
        {
            int sa = 0, sb = 0, sc = 0, cnt = 0;
            for (int j = 0; j < 7; j++)
                if (i >> j & 1)
                {
                    sa += s[j][0];
                    sb += s[j][1];
                    sc += s[j][2];
                    cnt++;
                }
            if (sa <= a && sb <= b && sc <= c)
                res = max(res, cnt);
        }
        cout << res << endl;
    }
}
