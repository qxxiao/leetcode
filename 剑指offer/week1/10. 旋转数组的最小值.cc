// https://www.acwing.com/problem/content/20/

// 使用二分
// 最坏情况下，需要遍历整个数组，找到最小值
#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int n = nums.size() - 1;
        if (n < 0)
            return -1;

        while (n && nums[n] == nums[0])
            n--;
        if (nums[n] >= nums[0])
            return nums[0];

        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};