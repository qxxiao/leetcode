/**
 * @file solution.cpp
 * @brief 有火，水，土三种药水，可以合成3种魔法
 * 魔法1：2火+1水
 * 魔法2：2水+1土
 * 魔法3：2土+1火
 * 现在有 火，水，土三种药水(a,b,c)个，求最多可以合成多少个魔法
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int max_magic_spells(int fire, int water, int earth) {
        int ans = 0;

        // 尝试制造不同数量的魔法1（需要2个火药水和1个水药水）
        for (int spell1 = 0; spell1 <= min(fire / 2, water); spell1++) {
            // 剩余的药水
            int remain_fire = fire - spell1 * 2;
            int remain_water = water - spell1;

            // 尝试制造魔法2（需要2个水药水和1个土药水）
            int max_spell2 = min(remain_water / 2, earth);
            int remain_earth = earth - max_spell2;

            // 尝试制造魔法3（需要2个土药水和1个火药水）
            int max_spell3 = min(remain_earth / 2, remain_fire);

            // 更新最大魔法数量
            ans = max(ans, spell1 + max_spell2 + max_spell3);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int a, b, c;

    // 读取输入
    int T = 100;
    srand(time(NULL));
    while (T--) {
        a = rand() % 1000000;
        b = rand() % 1000000;
        c = rand() % 1000000;

        cout << sol.max_magic_spells(a, b, c) << endl;
    }

    return 0;
}