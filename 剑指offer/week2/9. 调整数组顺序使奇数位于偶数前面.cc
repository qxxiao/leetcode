// https://www.acwing.com/problem/content/30/

#include <vector>
using namespace std;
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {

        if (array.empty())
            return;
        int i = 0, j = array.size() - 1;

        while (i < j)
        {
            while (array[i] % 2 == 1)
                i++;
            while (array[j] % 2 == 0)
                j--;
            if (i < j)
                swap(array[i], array[j]);
        }
    }
};