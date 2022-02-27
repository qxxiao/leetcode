// https://www.acwing.com/problem/content/15/
#include <vector>
using namespace std;

class Solution
{
public:
    int duplicateInArray(vector<int> &nums)
    {
        int n = nums.size();

        int l = 1, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int s = 0;
            for (auto x : nums)
                s += x >= l && x <= mid;
            if (s > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};