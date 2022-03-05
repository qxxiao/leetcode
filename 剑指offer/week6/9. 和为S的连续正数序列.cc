// https://www.acwing.com/problem/content/72/
// 经典的双指针问题---i,j,i递增时，j也递增，具有单调性

#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int sum)
    {

        vector<vector<int>> res;
        for (int i = 1, j = 1, s = 1; i <= sum / 2; i++)
        {
            while (s < sum)
                s += ++j;
            if (s == sum && j - i > 0)
            {
                vector<int> v;
                for (int k = i; k <= j; k++)
                    v.push_back(k);
                res.push_back(v);
            }
            s -= i;
        }
        return res;
    }
};