class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto x: nums){
            mp[x]++;
        }
        for(auto x:mp ){
            int key = x.first;
            int val = x.second;
            if(val>n/2) {
                return key;
                }
        }
        return -1;
    }
};