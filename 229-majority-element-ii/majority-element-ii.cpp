class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;
        int n =  nums.size();
        for(int ele:nums){
            m[ele]++;
        }
        for(auto ele: m){
            if(ele.second>n/3){
                v.push_back(ele.first);
            }
        }
        return v;
    }
};