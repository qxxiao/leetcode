// https : // www.acwing.com/problem/content/description/28/

// dp
#include <vector>
#include <string>
using namespace std;
class Solution
{
    string s, p;
    int n, m;
    vector<vector<bool>> f;

public:
    bool isMatch(string s_, string p_)
    {

        s = "-" + s_, p = "-" + p_;
        n = s_.size(), m = p_.size();
        f = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        // f[0][j>0]需要计算

        // 按位置遍历
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 0)
                {
                    f[i][j] = p[j] == '*' && f[i][j - 2];
                    continue;
                }
                if (p[j] != '*')
                    f[i][j] = (s[i] == p[j] || p[j] == '.') && (f[i - 1][j - 1]);
                else
                {
                    f[i][j] = f[i][j - 2] || (s[i] == p[j - 1] || p[j - 1] == '.') && (f[i - 1][j]);
                }
            }
        }

        return f[n][m];
    }
};