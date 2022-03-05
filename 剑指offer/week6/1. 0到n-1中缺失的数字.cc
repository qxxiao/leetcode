
// https://www.acwing.com/problem/content/64/

#include <vector>
using namespace std;
class Solution
{
public:
    int getMissingNumber(vector<int> &nums)
    {

        // 原来 0,1,2,3
        // 第一个nums[i]>i
        if (nums.empty())
            return 0;
        if (nums.back() == nums.size() - 1)
            return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};