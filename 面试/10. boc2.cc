/**
 * @file 10. boc2.cc
 *
 * 字符串，只存在大写字母和数字
 * 查找：
 * - 一串连续数字
 * - 如果数字之间有 "BAC" 的话可以消掉
 * - 数字可能很大
 * 返回字符串中符合规则的最大的数，如果没有数字返回 -1
 */
#include <cctype>
#include <string>
#include <regex>
#include <vector>
#include <iostream>

class Solution {
public:
    long long largestNumber(std::string &s) {
        std::string str = std::regex_replace(s, std::regex(R"(BAC)"), "");

        // std::cout << str << std::endl;
        std::vector<std::string> v;
        for (int i = 0; i < str.size(); i++) {
            if ((i == 0 || std::isupper(str[i - 1])) && std::isdigit(str[i])) {
                v.push_back("");
            }
            if (std::isdigit(str[i])) {
                v[v.size() - 1].push_back(str[i]);
            }
        }

        // 去除前面0
        std::sort(v.begin(), v.end(), [](const std::string &a, const std::string &b) {
            // 去除前导空格
            std::string sa, sb;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == '0' && sa.size() == 0 && i != a.size() - 1)
                    continue;
                sa.push_back(a[i]);
            }

            for (int i = 0; i < b.size(); i++) {
                if (b[i] == '0' && sb.size() == 0 && i != b.size() - 1)
                    continue;
                sb.push_back(b[i]);
            }

            if (sa.size() < sb.size())
                return true;
            else if (sa.size() > sb.size())
                return false;
            for (int i = 0; i < sa.size(); i++) {
                if (sa[i] < sb[i])
                    return true;
                else if (sa[i] > sb[i])
                    return false;
            }
            return false;
        });

        if (v.size() == 0)
            return -1;
        return std::stoll(v[v.size() - 1]);
    }
};

int main() {
    Solution s;
    std::string str = "2389HH123BAC99CCC888AAA1234";

    long long res = s.largestNumber(str);
    std::cout << res << std::endl;
}