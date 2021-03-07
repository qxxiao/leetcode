/**
 * @file 693.交替二进制数.cpp
 * @author qxxiao (1063064004@qq.com)
 * @brief https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
 * @version 1.0
 * @date 2021-03-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。 */

//s1 朴素版本
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int t0 = n & 1, t1;
        while (n >>= 1)
        {
            t1 = n & 1;
            if (t0 ^ t1 == 0)
                return false;
            t0 = t1;
        }
        return true;
    }
};

//s2 简洁版
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        while (n > 0)
        {
            if (n % 2 == (n / 2) % 2)
                return false;
            n /= 2;
        }
        return true;
    }
};

//s3 高效
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int temp = n ^ (n >> 1);
        return (temp & (temp + 1)) == 0;
    }
};
