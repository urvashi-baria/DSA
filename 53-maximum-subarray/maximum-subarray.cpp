class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentPrice = nums[0];
        int maxSum = nums[0];
        for(int i = 1;i<nums.size();i++){
            currentPrice = max(nums[i],currentPrice+nums[i]);
            maxSum = max(maxSum,currentPrice);
        }
        return maxSum;
    }
};