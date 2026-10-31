class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        if(nums.size()==0) {
            ans[0]=-1;
            ans[1]=-1;
            return ans;
        }
        if(nums.size()==1) {
            if(nums[0]==target){
                ans[0]=0;
                ans[1]=0;
            }
            else{
               ans[0]=-1;
               ans[1]=-1;
            }
            return ans;
        }
        int low = 0;
        int high = nums.size()-1;
        //firstOccur
        bool flag1=false;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]!=target) {
                    ans[0]=mid;
                    flag1=true;
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
        bool flag2=false;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                if(mid==nums.size()-1||nums[mid+1]!=target) {
                    ans[1]=mid;
                    flag2=true;
                    break;}
                else if(nums[mid+1]==target) l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        if(flag1==false && flag2==false){
            ans[0]=-1;
            ans[1]=-1;
        }
        return ans;
    }
};