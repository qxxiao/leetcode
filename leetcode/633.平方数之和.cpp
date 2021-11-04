#include <iostream>
#include <cmath>
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        //long 机器支持64
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
            {
                return true;
            }
        }
        return false;
    }
};