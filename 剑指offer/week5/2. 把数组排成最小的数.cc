// https://www.acwing.com/problem/content/54/
// 定义新的全序关系，a *< b <===> (ab) < (ba)
// 排序后连接的的数值最小

#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    static bool cmp(int a, int b)
    {
        string sa = to_string(a), sb = to_string(b);
        return sa + sb < sb + sa;
    }
    string printMinNumber(vector<int> &nums)
    {

        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (auto x : nums)
            res += to_string(x);

        return res;
    }
};