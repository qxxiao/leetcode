/**
 * @file 73. 矩阵置零.cpp
 * @author qxxiao
 * @brief https://leetcode-cn.com/problems/set-matrix-zeroes/
 * 原地算法，O(1)空间复杂度，标记算法
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        bool zerocol = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; //i行需要清0
                    if (j == 0)       //j列需要清0
                        zerocol = true;
                    else
                        matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            else
            {
                if (zerocol)
                    matrix[i][0] = 0;
                for (int j = 1; j < n; j++)
                    if (matrix[0][j] == 0)
                        matrix[i][j] = 0;
            }
        }
    }
};