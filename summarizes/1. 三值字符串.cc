/**
 * @file 1. 三值字符串.cpp
 * @details 给定一个字符串 s，其中的每个字符都是 1,2 或 3。
 * 请你求出同时包含字符 1,2,3 的 s 的最短子串的长度。注意，子串必须是连续的。
 *
 */

/****************************
 * Solution1: 数组存储其个数
 ***************************/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;
char s[N];
int cnt[5];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int n = strlen(s);
        memset(cnt, 0, sizeof cnt);

        int res = n + 1;
        for (int i = 0, j = 0; i < n; i++)
        {
            cnt[s[i] - '0']++;
            while (cnt[s[j] - '0'] > 1)
                cnt[s[j++] - '0']--;
            if (cnt[1] && cnt[2] && cnt[3])
                res = min(res, i - j + 1);
        }
        if (res == n + 1)
            cout << 0 << endl;
        else
            cout << res << endl;
    }
}
