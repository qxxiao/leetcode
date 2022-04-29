class Solution
{
public:
    bool searchArray(vector<vector<int>> array, int target)
    {

        if (array.empty() || array[0].empty())
            return false;
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0)
        {
            int x = array[i][j];
            if (x == target)
                return true;
            if (x > target)
                j--;
            else
                i++;
        }
        return false;
    }
};