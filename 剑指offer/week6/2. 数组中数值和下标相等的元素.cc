// https://www.acwing.com/problem/content/65/

#include <vector>
using namespace std;
class Solution
{
public:
    int getNumberSameAsIndex(vector<int> &nums)
    {

        // 划分的性质 nusm[i]<i
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] < mid)
                l = mid + 1;
            else
                r = mid;
        }

        if (nums[l] == l)
            return l;
        else
            return -1;
    }
};