#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int countSpecialNumbers(int n) {

        string sn = to_string(n);
        dp = vector<vector<int>>(sn.size(), vector<int>(1 << 10, -1));
        return dfs(sn, 0, 0, true, false);
    }

    int dfs(string& sn, int i, int mask, bool isLimit, bool isNum) {
        if (i == sn.size())
            return isNum ? 1 : 0;
        // 记忆化结果
        if (!isLimit && isNum && dp[i][mask] >= 0)
            return dp[i][mask];

        int res = 0;
        // 第 i 位可能选择跳过
        if (!isNum)
            res += dfs(sn, i + 1, mask, false, false);
        int up = isLimit ? (sn[i] - '0') : 9; // 可枚举的上界(isLimt)
        int down = isNum ? 0 : 1;             // 可枚举的下界(isNum)
        for (int x = down; x <= up; x++) {
            if ((mask >> x & 1) == 0) // == 优先级大于&
                res += dfs(sn, i + 1, mask | 1 << x, isLimit && x == up, true);
        }
        if (!isLimit && isNum) // 注意 受限制的以及跳过的不记忆
            dp[i][mask] = res; // 注意前面不要修改 mask
        return res;
    }
};