// https://www.acwing.com/problem/content/16/

#include <vector>
using namespace std;
class Solution
{
public:
    bool searchArray(vector<vector<int>> array, int target)
    {
        if (array.empty() || array[0].empty())
            return false;
        int row = array.size(), col = array[0].size();

        int r = 0, c = col - 1;
        while (r < row && c >= 0)
        {
            if (array[r][c] == target)
                return true;
            else if (target < array[r][c])
                c -= 1;
            else
                r += 1;
        }
        return false;
    }
};