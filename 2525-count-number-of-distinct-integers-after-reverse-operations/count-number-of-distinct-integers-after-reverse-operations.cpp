class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int ele:nums){
            s.insert(ele);
            int temp=ele;
            int rev = 0;
            while(temp>0){
                rev= rev*10+temp%10;
                temp=temp/10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};