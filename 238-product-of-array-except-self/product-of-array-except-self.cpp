class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefp(n);
        vector<int> sufp(n);
        prefp[0]=1;
        for(int i = 1;i<n;i++){
            prefp[i]=prefp[i-1]*nums[i-1]; 
        }
        sufp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            sufp[i]=sufp[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            nums[i]=sufp[i]*prefp[i];
        }

        return nums;
    }
};