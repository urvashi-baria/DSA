class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxSubArray=nums[0];
    for(int i =0;i<nums.size();i++){
        sum+=nums[i];
        maxSubArray = max(maxSubArray,sum);
        if(sum<0){
            sum=0;
        }
    }
      return maxSubArray;
    }
};