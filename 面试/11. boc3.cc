// 由 1,2,3组成的组成的数组
// 如果 2 两边分别是 1，3； 可以将1,3变成2
// 求最终数组中2的个数

#include <iostream>
#include <vector>

class Solution {
public:
    int numbers2(std::vector<int> &v) {
        int cnt = 0, idx = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 2) {
                cnt++;
                if (i != 0 && i != v.size() - 1) {
                    bool f1 = v[i - 1] == 1 && v[i + 1] == 3;
                    bool f2 = v[i + 1] == 1 && v[i - 1] == 3;

                    if (f1 || f2) {
                        // 避免 1 2 3 2 1 重复累加
                        if (i - 1 == idx)
                            cnt += 1;
                        else
                            cnt += 2;
                    }
                    idx = i + 1;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;

    std::vector<int> v{1, 2, 3, 2, 1, 1, 2, 3, 2, 2, 1};
    auto res = s.numbers2(v);
    std::cout << res << std::endl;
}