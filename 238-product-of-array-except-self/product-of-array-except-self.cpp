class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count  = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
        }
        int prod1 = 1;
        for(int i = 0;i<n;i++){
            prod1*=nums[i];
        }
        int prod2=1;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                continue; 
            }
            prod2*=nums[i];
        }

        vector<int> ans(n);
        if(count==0){
            for(int i = 0;i<n;i++){
                ans[i]=prod1/nums[i];
            }
        }
        else if(count==1){
           for(int i = 0;i<n;i++){
                if(nums[i]==0){
                   ans[i]=prod2;
            }
            else{
                ans[i]=0;
            }
           }  
        }
        else{
          for(int i = 0;i<n;i++){
            ans[i]=0;
          }  
        }
        return ans;
    }
};