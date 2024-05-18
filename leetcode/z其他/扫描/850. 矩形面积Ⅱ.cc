/**
 * @file 850. 矩形面积Ⅱ.cc
 * 离散化线性扫描+区间合并
 *
 */
#include <utility>
#include <vector>
using namespace std;
class Solution {

    const int mod = 1e9 + 7;

public:
    int rectangleArea(vector<vector<int>>& rts) {

        // 扫描线的离散坐标
        vector<int> xs;
        for (auto rt : rts) {
            xs.push_back(rt[0]);
            xs.push_back(rt[2]);
        }
        sort(xs.begin(), xs.end());
        // xs.erase(unique(xs.begin(), xs.end()), xs.end());

        long long res = 0;
        for (int i = 1; i < xs.size(); i++) {
            res += getArea(rts, xs[i - 1], xs[i]);
        }

        return res % mod;
    }

    // get unit area
    long long getArea(vector<vector<int>>& rts, int x1, int x2) {

        vector<pair<int, int>> vp;
        for (auto rt : rts) {
            if (rt[0] <= x1 && rt[2] >= x2) {
                vp.push_back({rt[1], rt[3]});
            }
        }
        // 区间合并
        sort(vp.begin(), vp.end());
        long long res = 0, start = -1, end = -1;
        for (auto p : vp) {
            if (p.first > end) {
                res += end - start;
                start = p.first;
                end = p.second;
            }
            else if (p.second > end) {
                end = p.second;
            }
        }
        // 最后一个连续区间
        res += end - start;
        return res * (x2 - x1);
    }
};