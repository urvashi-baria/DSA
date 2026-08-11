class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int low1 = 0;
        int high1 = n-1;
        int first_occur=-1;
        //first occurence
        while(low1<=high1){
            int mid = low1+(high1-low1)/2;
            if(nums[mid]==target){
                first_occur=mid;
                high1=mid-1;
            }
            else if(nums[mid]>target){
                high1=mid-1;
            }
            else{
                low1=mid+1;
            }
        }
        ans.push_back(first_occur);
        

        //last occurence
        int low2 = 0;
        int high2 = n-1;
        int last_occur = -1;

        while(low2<=high2){
            int mid = low2+(high2-low2)/2;
            if(nums[mid]==target){
                last_occur=mid;
                low2=mid+1;
            }
            else if(nums[mid]<target){
                low2=mid+1;
            }
            else{
                high2=mid-1;
            }
        }
        ans.push_back(last_occur);
        return ans;
    }
};