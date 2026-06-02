class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for(int i: nums){
            totalSum+=i;
        }
        int reqSum = totalSum-x;
        int windowSum=0;
        int len = -1;
        int left = 0,right=0;
        while(right<n){
            windowSum+=nums[right];
            while(left<=right && windowSum>reqSum){
                windowSum-=nums[left];
                left++;
            }
            if(windowSum==reqSum){
                len = max(right-left+1,len);
            }
            right++;
        }
        if(len==-1){
            return -1;
        }
        else{
            return n-len;
        }
    }
};