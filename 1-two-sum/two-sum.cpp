class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> s;
       for(int i = 0;i<nums.size();i++){
          int req = target-nums[i];
          if(s.count(req)){
            return {s[req],i};
          }
          s[nums[i]]=i;
       }  
       return {-1,-1};     
    }
};