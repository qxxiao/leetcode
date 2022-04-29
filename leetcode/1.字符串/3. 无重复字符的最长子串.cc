#include <map>
#include <string>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxlen = 0;
        map<char, int> usedChar;
        for (int index = 0; index < s.length(); index++) {
            //出现重复字符，并且起始位置<该重复字符最后出现的位置
            //要用count/find判断，如果用[]返回不存在的key则会插入返回value默认值，at抛出异常
            if (usedChar.count(s[index]) > 0 && start <= usedChar[s[index]]) {
                start = usedChar[s[index]] + 1;
            } else {
                maxlen = std::max(maxlen, index - start + 1);
            }
            //更新usedChar
            usedChar[s[index]] = index;
        }
        return maxlen;
    }
};