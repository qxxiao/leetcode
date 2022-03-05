// https://www.acwing.com/problem/content/description/78/

// 枪毙问题/约瑟夫环问题

// 解法1: 数组/链表模拟
#include <vector>
using namespace std;
class Solution
{
public:
    int lastRemaining(int n, int m)
    {

        vector<bool> r(n);
        int s = -1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                do
                    s = (s + 1) % n;
                while (r[s % n]);
            }
            r[s] = true;
        }
        for (int i = 0; i < n; i++)
            if (!r[i])
                return i;
        return -1; // not reachable
    }
};

// 递推， O(n)
class Solution2
{
public:
    int lastRemaining(int n, int m)
    {
        if (n == 1)
            return 0;
        return (lastRemaining(n - 1, m) + m) % n;
    }
};