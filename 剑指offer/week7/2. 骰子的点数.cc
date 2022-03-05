

// 递归，暴力枚举
// 容易  Time Limit Exceeded
//* 记忆化，递归出现的答案，可以记忆化为答案数组避免重复递归和计算
//* 或者直接动态规划
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> numberOfDice(int n)
    {
        vector<int> res;
        for (int i = n; i <= n * 6; i++)
            res.push_back(dfs(n, i));
        return res;
    }

    int dfs(int n, int sum)
    {
        if (sum < n) // 剪枝
            return 0;
        if (n == 0)
            return !sum;

        int res = 0;
        for (int i = 1; i <= 6; i++)
            res += dfs(n - 1, sum - i);
        return res;
    }
};

// 记忆化搜索
class Solution2
{
public:
    vector<vector<int>> f;

    vector<int> numberOfDice(int n)
    {
        vector<int> res;
        f = vector<vector<int>>(n + 1, vector<int>(6 * n + 1));
        f[0][0] = 1;

        for (int i = n; i <= 6 * n; ++i)
            res.push_back(dfs(n, i));
        return res;
    }

    int dfs(int n, int sum)
    {
        if (sum < n || sum > 6 * n)
            return 0;

        if (f[n][sum])
            return f[n][sum];
        for (int i = 1; i <= 6; ++i)
            f[n][sum] += dfs(n - 1, sum - i);
        return f[n][sum];
    }
};

// 迭代
class Solution3
{
public:
    vector<int> numberOfDice(int n)
    {

        if (n == 1)
            return {1, 1, 1, 1, 1, 1};
        vector<int> res{1, 2, 3, 4, 5, 6}; //前缀和
        vector<int> tmp;

        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j <= i * 6; j++)
            {
                int l = max(i - 1, j - 6) - (i - 1);       //左端点
                int r = min(6 * (i - 1), j - 1) - (i - 1); //右端点
                if (!l)
                    tmp.push_back(res[r]);
                else
                    tmp.push_back(res[r] - res[l - 1]);
            }
            res = tmp;
            if (i == n)
                break;
            //前缀和
            for (int k = 1; k < res.size(); k++)
                res[k] += res[k - 1];
            tmp.clear();
        }
        return res;
    }
};

// 动态规划
class Solution4
{
public:
    vector<int> numberOfDice(int n)
    {

        vector<vector<int>> f(n + 1, vector<int>(6 * n + 1));
        f[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= 6 * i; j++)
            {
                for (int k = 1; k <= min(6, j); k++)
                    f[i][j] += f[i - 1][j - k];
            }
        }
        vector<int> res;
        for (int j = n; j <= 6 * n; j++)
            res.push_back(f[n][j]);
        return res;
    }
};
