class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int sum = 0;
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                len = min(right-left+1,len);
                sum-=nums[left];
                left++;
            }
            right++;
        }
         if(len==INT_MAX){
            return 0;
         }
         return len;
    }
};