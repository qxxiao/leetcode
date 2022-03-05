// https://www.acwing.com/problem/content/75/

// 单调队列问题
// O(n)
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxInWindows(vector<int> &nums, int k)
    {

        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (q.size() && q.front() <= i - k)
                q.pop_front(); // 最多一个滑出窗口
            while (q.size() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};