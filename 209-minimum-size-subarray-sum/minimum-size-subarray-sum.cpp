class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        int i = 0;
        int j = i;
        int sum = 0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                int len = j-i+1;
                minLen = min(len,minLen);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return minLen==INT_MAX?0:minLen;
    }
};