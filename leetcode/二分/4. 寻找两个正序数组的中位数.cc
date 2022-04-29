// #include <climits>
#include <vector>
using namespace std;
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int totalLeft = (m + n + 1) / 2;
        // 0,1,...,m
        int l = 0, r = m;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            int j = totalLeft - mid;
            if (nums1[mid - 1] > nums2[j])
                r = mid - 1;
            else
                l = mid;
        }

        int nums1LeftMax = l == 0 ? INT_MIN : nums1[l - 1];
        int nums1RightMin = l == m ? INT_MAX : nums1[l];
        int nums2LeftMax = (totalLeft - l == 0) ? INT_MIN : nums2[totalLeft - l - 1];
        int nums2RightMin = (totalLeft - l == n) ? INT_MAX : nums2[totalLeft - l];
        if ((m + n) % 2 == 1)
            return max(nums1LeftMax, nums2LeftMax);
        else
            return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
    }
};