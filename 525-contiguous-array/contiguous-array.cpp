class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i]==1?1:-1;
            if(m.find(sum)!=m.end()){
                len=max(len,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
        return len;
    }
};