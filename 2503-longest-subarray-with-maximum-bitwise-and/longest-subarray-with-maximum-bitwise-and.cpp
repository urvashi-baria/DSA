class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int ans = 0;
        int count = 0;
        for(int x:nums){
            if(x==mx){
                count++;
                ans = max(ans,count);
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};