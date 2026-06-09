class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int max = 0;
        int idx = -1; //here by idx it means key that is the element
        for(auto ele:m){
            if(ele.second>max){
                max = ele.second;
                idx=ele.first;
            }
        } 
        return idx; 

    }
};