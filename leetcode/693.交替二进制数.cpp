/**
 * @file 693.交替二进制数.cpp
 * @brief https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
 *
 */

/* 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。 */

// s1 朴素版本
class Solution {
   public:
    bool hasAlternatingBits(int n) {
        int t0 = n & 1, t1;
        while (n >>= 1) {
            t1 = n & 1;
            if (t0 ^ t1 == 0) return false;
            t0 = t1;
        }
        return true;
    }
};

// s2 简洁版
class Solution2 {
   public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            if (n % 2 == (n / 2) % 2) return false;
            n /= 2;
        }
        return true;
    }
};

// s3 高效
class Solution3 {
   public:
    bool hasAlternatingBits(int n) {
        int temp = n ^ (n >> 1);
        return (temp & (temp + 1)) == 0;
    }
};
