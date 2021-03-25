/* 
给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

注意：

数据保证给定的表达式合法。
题目保证符号 - 只作为减号出现，不会作为负号出现，例如，-1+2,(2+2)*(-(1+1)+2) 之类表达式均不会出现。
题目保证表达式中所有数字均为正整数。
题目保证表达式在中间计算过程以及结果中，均不超过 231−1。
题目中的整除是指向 0 取整，也就是说对于大于 0 的结果向下取整，例如 5/3=1，对于小于 0 的结果向上取整，例如 5/(1−4)=−1。
C++和Java中的整除默认是向零取整；Python中的整除//默认向下取整，因此Python的eval()函数中的整除也是向下取整，在本题中不能直接使用。
输入格式
共一行，为给定表达式。

输出格式
共一行，为表达式的结果。

数据范围
表达式的长度不超过 105。

输入样例：
(2+2)*(1+1)
输出样例：
8
*/

//中缀表达式求值，二元运算符
//分为符号栈，数字栈；如果新遇到的符号优先级低于栈顶，则取栈顶元素计算

#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

stack<int> num;
stack<char> op;
unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{

    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    if (c == '+')
        num.push(a + b);
    else if (c == '-')
        num.push(a - b);
    else if (c == '*')
        num.push(a * b);
    else
        num.push(a / b);
}

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        auto c = s[i];
        if (isdigit(c))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
                x = x * 10 + s[j++] - '0';
            i = j - 1;
            num.push(x);
            continue;
        }

        if (c == '(')
            op.push(s[i]);
        else if (c == ')')
        {
            while (op.top() != '(')
                eval();
            op.pop();
        }
        else
        {
            while (op.size() && pr[s[i]] <= pr[op.top()])
                eval();
            op.push(s[i]);
        }
    }
    while (op.size())
        eval();
    cout << num.top() << endl;
    return 0;
}