// 根据 逆波兰表示法，求表达式的值。
// 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    stack<int> stk;

    void eval(string s) {
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();
        if (s == "+")
            stk.push(a + b);
        else if (s == "-")
            stk.push(a - b);
        else if (s == "*")
            stk.push(a * b);
        else
            stk.push(a / b);
    }
    int evalRPN(vector<string> &tokens) {
        unordered_set<string> s{"+", "-", "*", "/"};
        for (auto &t : tokens) {
            if (s.count(t))
                eval(t);
            else
                stk.push(stoi(t));
        }
        return stk.top();
    }
};