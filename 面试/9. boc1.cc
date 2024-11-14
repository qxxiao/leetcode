/**
 * @file 9. boc1.cc
 *
 * - 密码长度至少为10
 * - 只能包含大小写字母和数字
 * - 至少出现大小字母、小写字母、数字中的2种
 */

#include <string>
#include <regex>
#include <iostream>

class Solution {
public:
    bool check(std::string &mypassword) {
        // 密码长度至少为10
        if (mypassword.size() < 10)
            return false;
        // 只能包含大小写字母和数字
        if (!std::regex_match(mypassword, std::regex(R"([A-Za-z0-9]+)")))
            return false;
        // 至少出现大小字母、小写字母、数字中的2种
        int count1 = 0, count2 = 0, count3 = 0;
        for (char c : mypassword) {
            if (std::isupper(c))
                count1 = 1;
            else if (std::islower(c))
                count2 = 1;
            else if (std::isdigit(c))
                count3 = 1;
        }
        return (count1 + count2 + count3) >= 2;
    }
};

int main() {
    Solution s;
    std::string password = "Aa123456789.";
    std::cout << s.check(password) << std::endl;

    password = "12345678WWWW";
    std::cout << s.check(password) << std::endl;
}