class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        int k = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == size - 1 || nums[mid] > nums[mid + 1]) {
                k = mid;
                break;
            } else if (nums[mid] >= nums[low]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0;
        high = k;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    

        low = k + 1;
        high = size - 1;
        while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
 }
};
