

// 如果把子数组设定为至少m长应该怎么做？

// 可以用前缀和的思想。
// 枚举每个数nums[i] 作为右端点，那么寻找以该点为右端点的最大子段，等价于找该点左边的最小前缀和。
// 如果加上长度至少为m的限制，那么在寻找最小前缀和的时候，
// 只需要考虑0 ~i - m这部分就可以了，这里在枚举i的时候用一个变量记录一下0 ~i - m之间的最小前缀和就可以了，
// 时间复杂度 O(n)

#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        vector<int> f(nums.size());
        f[0] = nums[0];

        int res = f[0];
        for (int i = 1; i < nums.size(); i++)
        {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            res = max(res, f[i]);
        }

        return res;
    }
};