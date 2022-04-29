// https://www.acwing.com/problem/content/48/

// 摩尔投票法

#include <vector>
using namespace std;
class Solution
{
public:
    int moreThanHalfNum_Solution(vector<int> &nums)
    {

        int cnt = 0, x = -1;
        for (auto n : nums)
        {
            if (!cnt)
                cnt = 1, x = n;
            else
            {
                if (x == n)
                    cnt++;
                else
                    cnt--;
            }
        }
        return x;
    }
};