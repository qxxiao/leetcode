// https://www.acwing.com/problem/content/59/

#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    char firstNotRepeatingChar(string s)
    {

        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;

        for (auto c : s)
            if (map[c] == 1)
                return c;
        return '#';
    }
};