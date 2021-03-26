//要求 不使用64位存储

#include <string>
#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {

        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        string sign;
        if (s.back() == '-')
        {
            sign = "-";
            s.pop_back();
        }
        while (s.size() > 1 && s[0] == '0')
            s.erase(0, 1);
        string ss = sign + s;

        //判断0
        string smin = to_string(INT_MIN);
        string smax = to_string(INT_MAX);

        if (ss.size() > smin.size())
            return 0;
        else if (sign == "-" && ss.size() == smin.size() && ss > smin)
            return 0;
        else if (sign == "" && ss.size() == smax.size() && ss > smax)
            return 0;
        return stoi(ss);
    }
};

//如果可使用64位存储(long || long long)
int reverse(int x)
{
    long long n = 0;
    while (x)
    {
        n = n * 10 + x % 10;
        x /= 10;
    }
    return n > INT_MAX || n < INT_MIN ? 0 : (int)n;
}