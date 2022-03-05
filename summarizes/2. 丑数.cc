// https://www.acwing.com/problem/content/58/

#include <vector>
using namespace std;
class Solution
{
public:
    int getUglyNumber(int n)
    {

        // int cnt=1;

        // int res=1;
        // for(int i=2; cnt!=n; i++){

        //     int t=i;
        //     while(t%2==0) t/=2;
        //     while(t%3==0) t/=3;
        //     while(t%5==0) t/=5;
        //     if(t==1) cnt++, res=i;
        // }
        // return res;

        // O(n)：丑数从小到大进行扩展，扩展过程中选择 *2, *3, *5中最小的一个数
        // 将答案定义为丑数的顺序集合seq, 则seq= (2*seq) U (3*seq) U (5*seq) U 1
        // 注意可能出现相同的可扩展数

        vector<int> v(1, 1);
        int i = 0, j = 0, k = 0;
        while (--n)
        {
            int t = min(v[i] * 2, min(v[j] * 3, v[k] * 5));
            v.push_back(t);
            if (v[i] * 2 == t)
                i++;
            if (v[j] * 3 == t)
                j++;
            if (v[k] * 5 == t)
                k++;
        }
        return v.back();
    }
};