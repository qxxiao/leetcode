// 符号以及越界判断

#include <cstdint>
#include <string>
using namespace std;
class Solution {
   public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0, flag = 1;
        while (s[i] == ' ') i++;
        if (s[i] == '-') flag = -1;
        if (s[i] == '+' || s[i] == '-') i++;
        while (i < s.size() && isdigit(s[i])) {
            int r = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + r;
            i++;
        }
        return flag > 0 ? res : -res;
    }
};