class Solution {
public:
    int rev(int n){
        int reverse = 0;
             int digit;
             while (n>0){
                digit = n%10;
                reverse = reverse*10+digit;
                n = n/10;

             }
        return reverse;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            int r = rev(nums[i]);
            s.insert(nums[i]);
            s.insert(r);
        }
        return s.size();  
    }
};