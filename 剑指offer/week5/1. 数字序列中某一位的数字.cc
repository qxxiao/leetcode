// https://www.acwing.com/problem/content/52/

// 数位统计

class Solution
{
public:
    int digitAtIndex(int n)
    {
        // i:位数，个数， 基数
        long long i = 1, s = 9, base = 1;
        while (n > i * s)
        {
            n -= i * s;
            i++;
            s *= 10;
            base *= 10;
        }

        int num = base + (n + i - 1) / i - 1; //上取整
        int r = n % i ? n % i : i;
        for (int j = 0; j < i - r; j++)
            num /= 10;
        return num % 10;
    }
};