// https://www.acwing.com/problem/content/70/
// 在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

// https://www.acwing.com/activity/content/code/content/2742965/
#include <vector>
using namespace std;
// 按照位bit枚举
class Solution
{
public:
    int findNumberAppearingOnce(vector<int> &nums)
    {

        // nlnn 32n
        // 按照每一bit枚举
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int n = 0;
            for (auto x : nums)
            {
                if (x >> i & 1)
                    n++;
            }
            if (n % 3 == 1)
                res = res | (1 << i);
        }
        return res;
    }
};

// 状态机
class Solution2
{
public:
    int findNumberAppearingOnce(vector<int> &nums)
    {
        // 状态机表示，设定状态的bit位数为k, 2^k>=3==> k=2
        // (0,0) -1-> (1,0) -1-> (0,1)
        //   |                     |
        //   |<---------1----------|
        // s1' = (s1 ^ x) & ~s2;
        // s2' = (s2 ^ x) & (s1 | s2) = (s2 ^ x) & ~s1'
        int s1 = 0, s2 = 0;
        for (auto x : nums)
        {
            s1 = (s1 ^ x) & ~s2;
            s2 = (s2 ^ x) & ~s1;
        }
        return s1;
    }
};