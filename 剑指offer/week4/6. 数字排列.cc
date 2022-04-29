// https://www.acwing.com/problem/content/description/47/

#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> ans;
    vector<vector<int>> permutation(vector<int> &nums)
    {

        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());

        dfs(nums);
        return res;
    }

    void dfs(vector<int> remain)
    {
        if (remain.empty())
        {
            res.push_back(ans);
            return;
        }

        for (int i = 0; i < remain.size(); i++)
        {
            if (i && remain[i] == remain[i - 1])
                continue;
            ans.push_back(remain[i]);
            vector<int> t = remain;
            t.erase(t.begin() + i);
            dfs(t);
            ans.pop_back();
        }
    }
    // next_permutation(nums.begin(), nums.end())
};