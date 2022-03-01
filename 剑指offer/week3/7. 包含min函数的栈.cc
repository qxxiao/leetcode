// https://www.acwing.com/problem/content/90/

#include <vector>
using namespace std;
class MinStack
{
    vector<int> v;
    vector<int> m;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        v.push_back(x);
        if (m.size() == 0)
        {
            m.push_back(x);
        }
        else
            m.push_back(min(x, m[m.size() - 1]));
    }

    void pop()
    {
        if (v.size())
        {
            v.pop_back();
            m.pop_back();
        }
    }

    int top()
    {
        if (v.size())
        {
            return v[v.size() - 1];
        }
    }

    int getMin()
    {
        if (m.size())
        {
            return m[m.size() - 1];
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */