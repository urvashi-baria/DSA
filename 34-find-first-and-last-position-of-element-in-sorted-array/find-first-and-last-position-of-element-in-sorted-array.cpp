class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if(nums.size()==0) {
            ans[0]=-1;
            ans[1]=-1;
            return ans;
        }

        int low = 0;
        int high = nums.size()-1;
        //firstOccur
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]!=target) {
                    ans[0]=mid;
                    break;}
                else if(nums[mid-1]==target){
                   high=mid-1;
                }
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        
        //lastOccur
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                if(mid==nums.size()-1||nums[mid+1]!=target) {
                    ans[1]=mid;
                    break;}
                else if(nums[mid+1]==target) l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return ans;
    }
};