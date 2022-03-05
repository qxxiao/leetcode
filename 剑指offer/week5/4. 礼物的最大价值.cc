// https://www.acwing.com/problem/content/56/

#include <vector>
using namespace std;
class Solution
{
public:
    int getMaxValue(vector<vector<int>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> f(n, vector<int>(m));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){

        //         f[i][j]=max(j==0? 0:f[i][j-1], i==0?0:f[i-1][j])+grid[i][j];
        //     }
        // }
        // return f[n-1][m-1];

        // 解决边界问题,假设从1开始
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = max(f[i][j - 1], f[i - 1][j]) + grid[i - 1][j - 1];
        return f[n][m];
    }
};