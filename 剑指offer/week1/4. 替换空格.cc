// https://www.acwing.com/problem/content/17/

#include <string>
using namespace std;
class Solution
{
public:
    string replaceSpaces(string &str)
    {

        string res;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
                res += str[i];
            else
                res += "%20";
        }
        return res;
    }
};