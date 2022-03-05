// https://www.acwing.com/problem/content/80/

class Solution
{
public:
    int getSum(int n)
    {

        // return (long long)n*(n+1)/2;
        int res = n;
        n && (res += getSum(n - 1));
        return res;
    }
};