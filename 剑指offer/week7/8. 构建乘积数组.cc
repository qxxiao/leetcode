// https://www.acwing.com/problem/content/82/

#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {

        vector<int> B(A.size());

        for (int i = 0, p = 1; i < A.size(); i++)
        {
            B[i] = p;
            p *= A[i];
        }

        for (int i = A.size() - 1, p = 1; i >= 0; i--)
        {
            B[i] *= p;
            p *= A[i];
        }

        return B;
    }
};