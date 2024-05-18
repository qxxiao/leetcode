/**
 * @file 169. 多数元素.cc
 * @brief 给定一个大小为 n 的数组 nums ，返回其中的多数元素。
 * 多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 *
 */

//* 思路，摩尔投票法 Boyer-Moore Voting Algorithm
//* 以最坏的情况，所有的其他元素次数加起来都比不上多数元素，通过消耗计数器的方式，最后剩下的一定是多数元素

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res, c = 0;
        for (auto x : nums) {
            if (!c)
                res = x, c = 1;
            else if (res == x)
                c++;
            else
                c--;
        }
        return res;
    }
};