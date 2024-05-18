// 方法一
// 先将集合排序为B，然后来贪心匹配集合相等
// 遍历下标，如果集合B元素出现 hash表位置+1，集合A元素出现 hash表位置-1
// 维护当前集合 hash 表为非0 个数，如果为0表示匹配了一个集合
// 贪心继续遍历即可

// 方法二
// 集合划分的块是单调递增的, 使用单调栈来维护区间
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (auto x : arr) {
            int e = x;
            while (stk.size() && x < stk.top()) {
                e = max(e, stk.top());
                stk.pop();
            }
            // 如果 stk.size() == 0 或者 大于top()，则插入x
            // 如果小于top()，则混合后面的区间，弹出这些区间，插入整个区间的最大值
            stk.push(e);
        }
        return stk.size();
    }
};