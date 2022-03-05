// https://www.acwing.com/problem/content/73/

// 没有用额外的空间
// 分成两步来做，第一步是翻转整个句子，第二步是将单词反转为正确的单词
#include <string>
using namespace std;
class Solution
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

// 相似题目：左旋字符串，旋转矩阵
// https://www.acwing.com/problem/content/74/