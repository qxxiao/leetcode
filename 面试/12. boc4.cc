#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int numbersAAB(std::string &s) {
        std::vector<std::string> v;

        int start = -1, end = -1;
        for (int i = 0; i < s.size(); i++) {

            if (start == -1 && s[i] != ' ')
                start = i;
            if (start != -1 && (s[i] == ' ' || i == s.size() - 1)) {
                if (s[i] == ' ')
                    end = i - 1;
                else
                    end = i;
                v.push_back(s.substr(start, end - start + 1));
                start = -1;
            }
        }
        for (auto ss : v)
            std::cout << ss << std::endl;

        // count
        int cnt = 0;
        for (int i = 0; i < v.size() - 2; i++) {
            if (v[i] == v[i + 1] && v[i] != v[i + 2])
                cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    std::string str = "hello hello world hi hi hi Java";
    std::cout << s.numbersAAB(str) << std::endl;

    str = " hello hello world hi hi hi Java ";
    std::cout << s.numbersAAB(str) << std::endl;

    str = " hello hello world world hi hi hi Java ";
    std::cout << s.numbersAAB(str) << std::endl;
}