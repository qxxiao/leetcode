// https://www.acwing.com/problem/content/24/

// 1. 如果没有整数的限制，每段等长，接近n / e乘积最大
// 2. 如果每段都是整数，尽可能多分出来长度为3的段，如果最后长度为2则分出来一段；如果最后是1，则使用2 + 2代替原来的3 + 1

// 存在 ki >=5   分成3  3*（ki-3）>=ki
// 存在 ki=4,  分成 2*2 == 4 == ki
// 最多存在2个2，如果存在3个，2*2*2 < 3*3
class Solution
{
public:
    int maxProductAfterCutting(int length)
    {

        if (length <= 3)
            return length - 1;
        int res = 1;
        if (length % 3 == 1)
            res *= 4, length -= 4;
        else if (length % 3 == 2)
            res *= 2, length -= 2;

        while (length)
        {
            res *= 3;
            length -= 3;
        }
        return res;
    }
};