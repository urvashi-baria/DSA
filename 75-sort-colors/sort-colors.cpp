class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n = nums.size();
        // int noz = 0;
        // int noo = 0;
        // int notw = 0;
        // for(int i = 0;i<n;i++){
        //     if(nums[i]==0) noz++;
        //     else if(nums[i]==1) noo++;
        //     else notw++;
        // }

        // for(int i =0;i<n;i++){
        //     if(noz>0){
        //         nums[i]=0;
        //         noz--;
        //     }
        //     else if(noo>0) {
        //         nums[i]=1;
        //         noo--;}
        //     else if(notw>0) {
        //         nums[i]=2;
        //         notw--;
        //     }
        // }
        // return ;


        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
        }
        return;
    }
};