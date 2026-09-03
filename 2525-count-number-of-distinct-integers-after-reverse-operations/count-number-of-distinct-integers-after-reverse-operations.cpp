class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
           int rev = 0;
           int temp=nums[i];
           while(temp>0){
            rev=rev*10+temp%10;
            temp=temp/10;
           } 
           nums.push_back(rev);
        }

        unordered_set<int> s;
        for(int ele:nums){
            s.insert(ele);
        }
        return s.size();
    }
};