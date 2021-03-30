
/* 输入一个英文句子，单词之前用一个空格隔开，且句首和句尾没有多余空格。
 * 翻转句子中单词的顺序，但单词内字符的顺序不变。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        // string res(s.size(), ' ');
        // auto index=res.begin();
        // auto start=s.end(),end=s.end();
        // while(end!=s.begin()){
        //     while(start!=s.begin()&& *(start-1)!=' ' &&*start!=' ')
        //         start--;
        //     copy(start,end,index);
        //     std::advance(index,end-start);
        //     end=start;
        //     if(start!=s.begin())
        //         start-=1;
        // }
        // return res;

        //原地算法，步骤分解
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while (j < s.size() && s[j] != ' ')
                j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};