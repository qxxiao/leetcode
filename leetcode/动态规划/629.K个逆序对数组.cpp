
#include <vector>
#include <iostream> //for test
using namespace std;

class Solution
{
private:
	static constexpr int mod = 1000000007;

public:
	int kInversePairs(int n, int k)
	{
		vector<vector<int>> f(2, vector<int>(k + 1));
		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				int cur = i & 1, prev = cur ^ 1; //交替
				// 因为取模了,减法计算可能出现负数(以前的大数取模了)
				f[cur][j] = ((j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[prev][j - i] : 0) + f[prev][j]) % mod;
				if (f[cur][j] < 0)
					f[cur][j] += mod;
			}
		}
		return f[n & 1][k];
	}
};

int main()
{
	cout << Solution().kInversePairs(1000, 1000) << endl;
}