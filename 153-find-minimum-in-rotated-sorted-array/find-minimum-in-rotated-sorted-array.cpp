class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int min=INT_MAX;
        if(n==1){
            return nums[0];
        }
        if(n==2){
            if(nums[0]<nums[1]) return nums[0];
            else return nums[1];
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[low]<=nums[mid]){
              if(min>nums[low]){
                  min=nums[low];
              }
                  low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
              if(min>nums[mid]){
                  min=nums[mid];
              }
                high=mid-1;
            }
        }
        return min;
    }
};