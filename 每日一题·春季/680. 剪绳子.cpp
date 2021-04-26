/**
 * @file 680. 剪绳子.cpp
 * @author qxxiao (1063064004@qq.com)
 * @brief https://www.acwing.com/activity/content/code/content/1167996/
 * 二分
 * @version 1.0
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int N = 100010;
const double eps = 1e-4;
int n, m;
double len[N];

bool check(double mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += len[i] / mid;
    return cnt >= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> len[i];

    double l = 0, r = 1e9;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(2) << l << endl;
    return 0;
}