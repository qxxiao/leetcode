// https://www.acwing.com/problem/content/19/

class Solution
{
public:
    int Fibonacci(int n)
    {
        int a = 0, b = 1;
        while (n--)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};

// 扩展：求解斐波那契数列的若干方法
// https://www.acwing.com/blog/content/25/