// https://www.acwing.com/problem/content/73/

#include <string>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {

        string res;

        int i = s.size() - 1, j = s.size() - 1;
        while (i >= 0)
        {
            while (i >= 0 && s[i] != ' ')
                i--;
            res += s.substr(i + 1, j - i);
            if (i != -1)
                res += " ";
            j = i - 1;
            i--;
        }
        return res;
    }
};

// 没有用额外的空间
// 分成两步来做，第一步是翻转整个句子，第二步是将单词反转为正确的单词
class Solution2
{
public:
    string reverseWords(string s)
    {

        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while (j < s.size() && s[j] != ' ')
                ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};