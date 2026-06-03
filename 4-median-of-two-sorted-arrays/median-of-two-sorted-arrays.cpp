class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            nums1.swap(nums2);
            swap(m, n);
        }

        int low = 0, high = m;
        int total = m + n;
        int half = (total + 1) / 2;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = half - i;

            int left1 = i == 0 ? INT_MIN : nums1[i - 1];
            int right1 = i == m ? INT_MAX : nums1[i];
            int left2 = j == 0 ? INT_MIN : nums2[j - 1];
            int right2 = j == n ? INT_MAX : nums2[j];

            if (right1 >= left2 && right2 >= left1) {
                if (total % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            }
            if (left1 > right2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return -1;
    }
};