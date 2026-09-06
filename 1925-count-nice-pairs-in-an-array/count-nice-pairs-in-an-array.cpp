class Solution {
public:
    int rev(int num){
        int temp=num;
        int reverse = 0;
        while(temp>0){
            reverse=reverse*10+temp%10;
            temp=temp/10;
        }
        return reverse;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        long long count = 0;
        const long long MOD = 1e9+7;
        for(int i = 0;i<n;i++){
            int diff = nums[i]-rev(nums[i]);
            if(m.find(diff)!=m.end()){
                count=(count+m[diff])%MOD;
            }
            m[diff]++;
        }
        
        return count;
    }
};