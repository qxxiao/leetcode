

// 解法思路有很多

class Solution
{
public:
    int NumberOf1(int n)
    {

        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
                res++;
        }
        return res;
    }
};

class Solution2
{
public:
    int NumberOf1(int n)
    {

        unsigned int m = n;
        int res = 0;
        while (m)
        {
            res += 1 & m;
            m >>= 1;
        }
        return res;
    }
};