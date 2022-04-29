// https://www.acwing.com/problem/content/description/88/

// O(nlgn)
// max堆中的数量 最多比min堆中的数量多1（总数为奇数的情况）
// max堆的堆顶应该<=min堆的堆顶
#include <queue>
using namespace std;
class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    void insert(int num)
    {

        max_heap.push(num);
        if (max_heap.size() - min_heap.size() >= 2)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() && max_heap.top() > min_heap.top())
        {
            int x = max_heap.top();
            int y = min_heap.top();
            max_heap.pop(), min_heap.pop();
            max_heap.push(y), min_heap.push(x);
        }
    }

    double getMedian()
    {
        int n = max_heap.size() + min_heap.size();
        if (n & 1)
            return max_heap.top();
        else
            return (max_heap.top() + min_heap.top()) / 2.0;
    }
};
