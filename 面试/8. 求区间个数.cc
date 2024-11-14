/**
 * @file 8. 求区间个数.cc
 * @author qxxiao
 * @date 2024-10-26
 *
 * 输入1，一个包含多个正整数的数组 len>=1(不重复)
 * 输入2，两个正整数 x>=1, k>=0
 * @brief 求数组中2个整数（可重复）构成的区间 [L, R] 个数，区间中的正整数恰好有 k 个整数能被 n  整除
 * （即：在数组中，包含 k 个可以被 x 整除的数的区间的数量）
 * eg. a=[1,2,3,4]  a = 2, k = 1 ret. 6
 * 解释，包括 [1,2] [1,3] [2,2] [2,3] [3,4] [4,4]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    // 不考虑排序的情况下：这里最坏情况下是 len(a) * n
    // 暴力循环 i,j 是 O(len^2)
    long long kinterval(vector<int> &a, int x, int k) {
        result.clear(); // 装载答案区间
        long long res = 0;
        std::sort(a.begin(), a.end());

        int j = 0;
        for (int i = 0; i < a.size(); i++) {
            // 在 j 到达末尾，或者是 j 到达下一个分界点（res++时）
            // 回退 j （最多n）, 可能获取更多的 [i,j]区间, 它们 cnt 都相等
            for (; j < a.size(); j++) {
                int cnt = mcount(a[i], a[j], x);
                if (cnt == k) {
                    res++;
                    result.push_back({a[i], a[j]});
                }
                else if (cnt > k) {
                    j = std::max(i + 1, j - x);
                    break;
                }
            }
            if (j >= a.size() && mcount(i, j - 1, x) >= k) {
                j = std::max(i + 1, j - x);
            }
        }
        return res;
    }

    // 计算区间  [L, R] 中能被 n 整除的数的个数
    // TODO: 也可用前缀和来计算
    int mcount(int L, int R, int x) {
        return R / x - (L - 1) / x;
    }

    // debug: print interval
    void printInterval() {
        for (auto &interval : result) {
            cout << "[" << interval[0] << "," << interval[1] << "] ";
        }
        cout << endl;
    }
};

int main() {
    Solution solution;

    vector<int> a = {1, 2, 3, 4};
    // [1,2] [1,3] [2,2] [2,3] [3,4] [4,4]
    std::cout << solution.kinterval(a, 2, 1) << std::endl; // 6

    solution.printInterval();

    a = {2, 4, 8, 10};
    std::cout << solution.kinterval(a, 2, 2) << std::endl;
    solution.printInterval();

    a = {1, 2, 3, 4, 5, 6, 7};
    std::cout << solution.kinterval(a, 4, 1) << std::endl;
    solution.printInterval();
}