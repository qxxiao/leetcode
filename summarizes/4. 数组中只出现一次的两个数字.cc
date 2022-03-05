// https://www.acwing.com/problem/content/69/
// 经典的异或问题，按位分类在异或

#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findNumsAppearOnce(vector<int> &nums)
    {

        int sum = 0;
        for (auto x : nums)
            sum ^= x; // x^y
        int k = 0;
        while (!(sum >> k & 1))
            k++;
        int left = 0;
        for (auto x : nums)
            if (x >> k & 1)
                left ^= x;
        return vector<int>{left, sum ^ left};
    }
};