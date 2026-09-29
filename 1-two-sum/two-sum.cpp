class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int idx1 = -1;
       int idx2 = -1;
       int n = nums.size();
       vector<int> ans;
       for(int i = 0;i<n-1;i++){
         int idx = i;
         int rem = target-nums[i];
         for(int j=i+1;j<n;j++){
            if(nums[j]==rem){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
         }
       }
       return ans;
    }
};