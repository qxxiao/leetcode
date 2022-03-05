// https://www.acwing.com/problem/content/description/81/

// num1 + num2 == sum + carry(进位和)
// 每次循环，进位和最少*2, 因此循环会结束
class Solution
{
public:
    int add(int num1, int num2)
    {

        while (num2)
        {
            int sum = num1 ^ num2;
            int carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};