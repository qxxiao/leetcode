// https://www.acwing.com/problem/content/40/

#include <vector>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isPopOrder(vector<int> pushV, vector<int> popV)
    {

        if (pushV.size() != popV.size())
            return false;

        stack<int> stk;
        int i = 0;
        for (auto x : pushV)
        {
            stk.push(x);
            while (stk.size() && stk.top() == popV[i])
            {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};