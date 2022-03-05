

// ab|c|de, 枚举数位c,
// 0~ab-1  * 10^(2) ==left *t
// ab 如果c==1, de+1 ==right+1
// ab    c>1,  10^(2) ==t

#include <vector>
using namespace std;
class Solution
{
public:
    int numberOf1Between1AndN_Solution(int n)
    {

        // int res=0;
        // for(int i=1;i<=n;i++){

        //     int t=i;
        //     while(t){
        //         if(t%10==1) res++;
        //         t/=10;
        //     }
        // }
        // return res;

        vector<int> num;
        while (n)
            num.push_back(n % 10), n /= 10;
        int res = 0;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            auto left = 0, right = 0, t = 1; // t右边数位的最大个数
            for (int j = num.size() - 1; j > i; j--)
                left = left * 10 + num[j];
            for (int j = i - 1; j >= 0; j--)
                right = right * 10 + num[j], t *= 10;
            res += left * t;
            if (num[i] == 1)
                res += right + 1;
            else if (num[i] > 1)
                res += t;
        }
        return res;
    }
};