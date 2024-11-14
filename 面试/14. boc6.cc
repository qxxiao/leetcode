// 求 01??01 字符串，其中 ? 可以是0或1，求最多的相邻数字不同的对数，字符串只包含0/1/？

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxDifferentPairs(const string &s) {
    int n = s.length();
    vector<int> dp0(n, 0); // dp0[i] 表示前 i 个位置, 并且s[i]=0 时，最大相邻不同对数
    vector<int> dp1(n, 0);

    for (int i = 1; i < n; i++) {
        // s[i] 是 0/1
        if (s[i] != '?' && s[i] == s[i - 1]) {
            if (s[i] == '0')
                dp0[i] = dp0[i - 1];
            else
                dp1[i] = dp1[i - 1];
            continue;
        }
        if (s[i] != '?') {
            if (s[i] == '0') {
                dp0[i] = s[i - 1] == '1' ? (dp1[i - 1] + 1) : (std::max(dp0[i - 1], dp1[i - 1] + 1));
            }
            else {
                dp1[i] = s[i - 1] == '0' ? (dp0[i - 1] + 1) : (std::max(dp0[i - 1] + 1, dp1[i - 1]));
            }
            continue;
        }
        // s[i] 是 ？
        if (s[i - 1] == '0') {
            dp0[i] = dp0[i - 1];
            dp1[i] = dp0[i - 1] + 1;
            continue;
        }
        if (s[i - 1] == '1') {
            dp0[i] = dp1[i - 1] + 1;
            dp1[i] = dp1[i - 1];
            continue;
        }
        dp0[i] = std::max(dp0[i - 1], dp1[i - 1] + 1);
        dp1[i] = std::max(dp0[i - 1] + 1, dp1[i - 1]);
    }

    if (s.back() == '0')
        return dp0[n - 1];
    if (s.back() == '1')
        return dp1[n - 1];
    return std::max(dp0[n - 1], dp1[n - 1]);
}

// 也可以直接求
int maxDifferentPairs2(const string &s) {
    // 前缀 ？/后缀 ？
    int n = s.size();
    int i = 0, j = n - 1, res = 0;
    while (s[i] == '?')
        i++, res++;
    // end?
    if (i >= n) {
        return res - 1;
    }
    while (s[j] == '?')
        j--, res++;
    for (int k = i; k <= j; k++) {
        if (s[k] != '?') {
            if (k != i && s[k] != s[k - 1])
                res++;
            continue;
        }
        int start = k;
        while (s[k] == '?') {
            k++;
        }
        int len = k - start;
        if (((len % 2) + (s[start - 1] - '0' + s[k] - '0')) % 2 == 1) {
            res += len + 1;
        }
        else
            res += len;
    }
    return res;
}

int main() {
    string s;
    int result, result2;
    while (true) {
        cout << "请输入字符串 (只包含 0, 1 和 ?): ";
        cin >> s;

        result = maxDifferentPairs(s);
        result2 = maxDifferentPairs2(s);
        cout << "最多的相邻数字不同的对数: " << result << " " << result2 << endl;
        cout << endl;
    }

    return 0;
}