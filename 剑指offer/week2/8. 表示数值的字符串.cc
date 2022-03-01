// https://www.acwing.com/problem/content/29/

#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {

        int e = 0, pos = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
                e++, pos = i;
        }
        if (e > 1)
            return false;
        if (e == 0)
            return isFloat(s);
        return isFloat(s.substr(0, pos)) && isInt(s.substr(pos + 1), true); // int不能为空
    }

    bool isInt(string s, bool flag)
    {

        if (flag && (s[0] == '+' || s[0] == '-'))
            s = s.substr(1);
        if (s.empty())
            return false; //不能为空 [+-""  | ""]
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
                return false;
        }
        return true;
    }

    // 整数或浮点数
    bool isFloat(string s)
    {
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        string::size_type pos = s.find(".", 0);
        if (pos == string::npos)
            return isInt(s, false);
        else
        {
            if (s.size() == 1)
                return false;
            // 左边长度 右边长度
            return (pos == 0 || isInt(s.substr(0, pos), false)) && (s.size() - 1 - pos == 0 || isInt(s.substr(pos + 1), false));
        }
    }
};