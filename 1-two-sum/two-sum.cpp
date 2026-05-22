class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> idx;
        for(int i = 0;i<nums.size();i++){
            int n = target-nums[i];
            if(m.find(n)==m.end()){
                m[nums[i]] = i;
            }
            else{
                idx.push_back(i);
                idx.push_back(m[n]);
                return idx;
            }
        }
        return idx;
        
    }
};