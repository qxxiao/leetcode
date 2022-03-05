// https://www.acwing.com/problem/content/83/

// 从第一个非空格字符开始

#include <string>
using namespace std;
class Solution
{
public:
    int strToInt(string str)
    {
        int k = 0;
        long long number = 0;
        bool is_minus = false; // 判断是否是负数
        while (k < str.size() && str[k] == ' ')
            k++;
        if (str[k] == '+')
            k++;
        else if (str[k] == '-')
            is_minus = true, k++;

        while (k < str.size() && str[k] <= '9' && str[k] >= '0')
        {
            number = number * 10 + (str[k] - '0');
            if (is_minus && number * (-1) < INT_MIN)
            {
                number = INT_MIN;
                break;
            }
            if (!is_minus && number > INT_MAX)
            {
                number = INT_MAX;
                break;
            }
            k++;
        }
        // INT_MIN --> INT_MAX+1取int时，仍然是 INT_MIN
        if (is_minus)
            number *= -1;

        return (int)number;
    }
};
