class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int  i = 0;i<n;i++){
            if(nums[i]==0){
                nums[i] = -1;
            }
        }
        unordered_map<int,int> m;
        int currentSum = 0;
        int maxLen = 0;
        m[0]=-1;
        for(int j = 0;j<n;j++){
            currentSum+=nums[j];
            if(m.find(currentSum)!=m.end()){
                int length = j-m[currentSum];
                maxLen = max(maxLen,length);
            }
            else{
                m[currentSum]=j;
            }
        }
        return maxLen;
    }
};