class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int freq:nums){
            mp[freq]++;
        }

        for(auto ele:mp){
            if(ele.second==1){
                return ele.first;
            }
        }
        return 0;
    }
};