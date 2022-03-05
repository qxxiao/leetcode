// https://www.acwing.com/problem/content/79/

#include <vector>
using namespace std;
class Solution
{
public:
    int maxDiff(vector<int> &nums)
    {

        if (nums.size() < 1)
            return 0;
        int pre = 0, ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int x = nums[i] - nums[i - 1];
            if (pre > 0)
                x += pre;
            ans = max(ans, x);
            pre = x;
        }
        return ans;
    }
};