// https://www.acwing.com/problem/content/description/71/

#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> findNumbersWithSum(vector<int> &nums, int target)
    {

        // 需要注意x==target-x
        // unordered_map<int, int> map;
        // for(auto x: nums) map[x]=1;
        // for(auto x:nums)
        //     if(x==target-x && map[x]>1 || x!=target-x && map[target-x]) return vector<int>{x, target-x};

        // 简单写法, 先判断后插入
        unordered_set<int> s;
        for (auto x : nums)
        {
            if (s.count(target - x))
                return vector<int>{target - x, x};
            else
                s.insert(x);
        }
        return vector<int>();
    }
};