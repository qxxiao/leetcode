// https://www.acwing.com/problem/content/49/

#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k)
    {

        // sort(input.begin(), input.end());
        // vector<int> v;

        // for(int i=0;i<k;i++)    v.push_back(input[i]);
        // return v;

        // 大根堆的方法
        priority_queue<int> q;
        for (auto x : input)
        {
            q.push(x);
            if (q.size() > k)
                q.pop();
        }

        vector<int> v;
        while (!q.empty())
            v.push_back(q.top()), q.pop();
        reverse(v.begin(), v.end());
        return v;
    }
};