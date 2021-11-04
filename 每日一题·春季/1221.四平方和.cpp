//

//给定N,求
//0<=a<=b<=c<=d, a^2+b^2+c^2+d^2=N;
// 0<N<5*1000000;
//字典序最小

/****************************
 * 这种求和问题，注意时间复杂度 O(n)
 * 分组 a+b, c+d
 */

#include <iostream>
#include <cstring>
// #include <unordered_set>     //time limit exceed

using namespace std;

const int N = 5 * 1000000;
int a, b, c, d;
int n;
// unordered_map<int, pair<int,int>> m;
int C[N], D[N];

int main()
{
    cin >> n;
    // for(int i=0;i<=n;i++)
    //     C[i]=-1;
    // 0 -1 use memset
    memset(C, -1, sizeof C);
    //c d
    for (c = 0; c * c <= n; c++)
    {
        for (d = c; c * c + d * d <= n; d++)
        {
            int s = c * c + d * d;
            if (C[s] == -1)
                C[s] = c, D[s] = d;
        }
    }

    bool f = false;
    for (a = 0; 4 * a * a <= n; a++)
    {
        for (b = a; a * a + b * b <= n; b++)
        {
            int s = n - a * a - b * b;
            if (C[s] != -1)
            {
                c = C[s];
                d = D[s];
                f = true;
                break;
            }
        }
        if (f)
            break;
    }
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
