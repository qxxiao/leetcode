#include <vector>
using namespace std;

class Solution
{
    vector<int> t;
    vector<vector<int>> res;

public:
    void dfs(vector<int> &nums, int n)
    {
        if (n >= nums.size())
        {
            res.push_back(t);
            return;
        }
        dfs(nums, n + 1);
        t.push_back(nums[n]);
        dfs(nums, n + 1);
        t.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        // res.push_back(vector<int>());
        dfs(nums, 0);
        return res;
    }
};
