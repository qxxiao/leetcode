// https://www.acwing.com/problem/content/26/

// 快速幂算法

class Solution
{
public:
    double Power(double base, int exponent)
    {

        if (exponent == 0)
            return 1;
        bool f = exponent < 0;
        long long exp = exponent;
        if (f)
            exp = -exp;

        double res = 1.0;
        while (exp)
        {
            if (exp & 1)
            {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }

        if (f)
            res = 1 / res;
        return res;
    }
};