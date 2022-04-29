//单调栈问题

//枚举每个ai（aj),从后往前枚举
//如果存在，则维护当前ai后面满足要求的最大ak(有就有最大的)
#include <vector>
#include <stack>
#include <climits>
using namespace std;
class Solution
{
public: 
    bool find132pattern(vector<int> &nums)
    {

        int ak = INT_MIN;
        stack<int> stk;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < ak)
                return true;
            while (stk.size() && stk.top() < nums[i])
            {
                ak = max(ak, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
