// 解法1: 分治  【577 平面最近点对 分治算法【计算几何】】
// https://www.bilibili.com/video/BV1ko4y1s7Ed/?share_source=copy_web&vd_source=ee857f9722a02016d68d360bb5ed453f
// 解法2: 统计序列 【本方法】

// 维护集合 以y为第一关键字、 x为第二关键字排序的 multiset
// 对于点集 0～i 中存在最近点对的集合
// todo 首先把所有点按照x为第一关键字、 为y第二关键字排序
// 考虑点 xi
// 1. 将所有满足 xi-xj >=d 的点从集合中删除。它们不会再对答案有贡献
// 2. 集合内满足 |yi-yj|<d 的所有点，统计它们和pi的距离(也是有限的)
// 3. 将点 pi 插入到集合

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
const int N = 200005;
int n;
double ans = 1e20;

struct point {
    double x, y;

    point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct cmp_x {
    bool operator()(const point& a, const point& b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const point& a, const point& b) const {
        return a.y < b.y;
    }
};

inline void upd_ans(const point& a, const point& b) {
    double dist = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    if (ans > dist)
        ans = dist;
}

point a[N];
std::multiset<point, cmp_y> s;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    // 按照x为第一关键字、 y为第二关键字排序
    std::sort(a, a + n, cmp_x());
    // 每一个位置 i 来 维护集合
    for (int i = 0, l = 0; i < n; i++) {
        // 删除掉所有满足 xi-xj >=d 的点(注意是从小到大添加的点，考虑 l<i)
        while (l < i && a[i].x - a[l].x >= ans)
            s.erase(s.find(a[l++]));
        // 统计满足 |yi-yj|<d 的所有点，统计它们和pi的距离(也是有限的)
        // 最多5个点
        for (auto it = s.lower_bound(point(a[i].x, a[i].y - ans)); it != s.end() && it->y - a[i].y < ans; it++)
            upd_ans(*it, a[i]);
        s.insert(a[i]);
    }
    printf("%.4lf", ans);
    return 0;
}