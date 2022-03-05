// https://www.acwing.com/problem/content/74/

#include <string>
using namespace std;
class Solution
{
public:
    string leftRotateString(string str, int n)
    {

        // return str.substr(n, str.size()-n)+str.substr(0,n);

        // 空间复杂度O(1)的做法
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};