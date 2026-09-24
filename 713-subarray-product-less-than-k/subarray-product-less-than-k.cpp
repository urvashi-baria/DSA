class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      if(k<=1) return 0;
      int n = nums.size();
      int i = 0;
      int j = 0;
      int count = 0;
      long long prod = 1;
      while(j<n){
        prod*= (long long)nums[j];
      
        while(prod>=k){
           prod=prod/(long long)nums[i];
           i++;
        } 
        count += j-i+1;
        j++;
      }
      return count;
    }    
};