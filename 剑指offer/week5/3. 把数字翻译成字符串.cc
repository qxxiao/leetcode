// https://www.acwing.com/problem/content/55/
// 线性dp

#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int getTranslationCount(string s)
    {

        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1];
            if (i > 1)
            {
                int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (t >= 10 && t <= 25)
                    f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};