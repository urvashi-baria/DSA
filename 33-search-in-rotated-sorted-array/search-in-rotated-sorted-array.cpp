class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        if (n == 2) {
            if (nums[0] == target)
                return 0;
            else if (nums[1] == target)
                return 1;
            else
                return -1;
        }

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // left sorted
            if (nums[low] <= nums[mid])
                if (target >= nums[low] && target <nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            else if (nums[mid + 1] <= nums[high]) {
                if (target >nums[mid] && target <=nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            else return -1;
        }
        return -1;
    }
};