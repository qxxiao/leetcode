// https://www.acwing.com/problem/content/description/61/

//* 暴力枚举 n^2
#include <vector>
using namespace std;
class Solution
{
public:
    int inversePairs(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] > nums[j])
                    res++;
        }
        return res;
    }
};

//* 分治法，利用归并排序的过程计算逆序对
class Solution2
{
public:
    int inversePairs(vector<int> &nums)
    {

        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int> &nums, int l, int r)
    {
        if (r - l < 1)
            return 0;

        int mid = l + r >> 1;
        int res = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        vector<int> v(r - l + 1);
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
                v[k++] = nums[i++];
            else
            {
                res += mid - i + 1;
                v[k++] = nums[j++];
            }
        }
        while (i <= mid)
            v[k++] = nums[i++];
        while (j <= r)
            v[k++] = nums[j++];
        for (int k = 0; k < r - l + 1; k++)
            nums[l + k] = v[k];

        return res;
    }
};