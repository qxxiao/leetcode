//原来的集合运行重复的元素
//求幂集，所有的子集

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> path;
    unordered_map<int, int> cnt;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        for (auto x : nums)
            cnt[x]++;
        dfs(cnt.begin());
        return res;
    }

    void dfs(unordered_map<int, int>::iterator it)
    {
        if (it == cnt.end())
            res.push_back(path);
        else
        {
            for (int i = 0; i <= (*it).second; i++)
            {
                dfs(std::next(it, 1));
                path.push_back((*it).first);
            }
            for (int i = 0; i <= (*it).second; i++)
                path.pop_back();
        }
    }
};

// int main()
// {
//     Solution s;
//     vector<int> a{1};
//     auto res = s.subsetsWithDup(a);
//     cout << "[ ";
//     for (auto &v : res)
//     {
//         cout << "[";
//         for (auto n : v)
//             cout << n << ",";
//         cout << "],";
//     }
//     cout << " ]" << endl;
//     cout << "hello" << endl;
// }