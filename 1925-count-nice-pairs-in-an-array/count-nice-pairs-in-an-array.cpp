class Solution {
public:
    int rev(int nums){ 
        int reverse = 0;
        while(nums!=0){  
           int digit = nums%10;
           reverse= reverse*10+digit;
           nums = nums/10;
        }
        return reverse;
    }
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9+7;
        long long count = 0;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                count=(count+m[nums[i]])%MOD;
            }
            m[nums[i]]++;
        }
        return count;
    }
};