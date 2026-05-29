class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        unordered_set<int> s;
          
        for(int ele: nums){
            m[ele]++;
        }
        int maxFreq = INT_MIN;
        int maxNum = INT_MIN;
        for(auto ele:m){
            if(ele.second>maxFreq){
                maxFreq = ele.second;
                maxNum = ele.first;
            }
        }
        return maxNum;
    }
};