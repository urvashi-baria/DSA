class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n = nums.size();
       int len;
       int maxLen = INT_MIN;
       int i=0;
       int j=0;
       int del = 0;
       while(j<n){
        if(nums[j]==1) j++;
        else{
            if(del==0){
                j++;
                del++;
            }
            else if(del==1){
                len = j-i-1;
                maxLen = max(len,maxLen);
                while(nums[i]==1) i++;
                i++;
                j++;
            }
        }
       }
       len = j-i-1;
       maxLen = max(maxLen,len);
       return maxLen;
    }
};