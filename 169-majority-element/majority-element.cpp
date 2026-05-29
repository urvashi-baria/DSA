class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
          
        for(int ele:nums){
            m[ele]++;
            if(m[ele]>n/2){
                return ele;
            }
        }
        return -1;
    }
};