// https://www.acwing.com/problem/content/1454/

// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].

#include <vector>
#include <iostream>
using namespace std;

int matrix[100][100];
int query(int x, int y)
{
    return matrix[x][y];
}

class Solution
{

public:
    int colMin(int n, int col)
    {
        int m = query(0, col), row = 0;
        for (int i = 1; i < n; i++)
        {
            int e = query(i, col);
            if (e < m)
                m = e, row = i;
        }
        return row;
    }

    vector<int> getMinimumValue(int n)
    {

        vector<int> v;
        int l = 0, r = n - 1, row;
        while (l < r)
        {
            int mid = l + r >> 1;
            row = colMin(n, mid);
            int e = query(row, mid);

            // 比左右都小
            if (((mid - 1 < l) || e < query(row, mid - 1)) && ((mid + 1 > r) || e < query(row, mid + 1)))
            {
                v.push_back(row);
                v.push_back(mid);
                return v;
            }

            // 只有一侧
            if (mid - 1 < l)
                l = mid + 1;
            else if (mid + 1 > r)
                r = mid - 1;
            // 取最小的一侧
            else if (query(row, mid - 1) < query(row, mid + 1))
                r = mid - 1;
            else
                l = mid + 1;
        }
        row = colMin(n, l);
        v.push_back(row);
        v.push_back(l);
        return v;
    }
};
