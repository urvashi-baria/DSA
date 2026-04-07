class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int x = nums[i];
            mp[x]++;
        }

        for(auto x:mp){
            int key = x.first;
            int val = x.second;
            if(x.second>1){
                return x.first;
            }
        }
        return -1;

    }
};