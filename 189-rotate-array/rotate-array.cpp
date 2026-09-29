class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        while(k>n){
            k=k-n;
        }
        //reverse entire array;
        int i = 0;
        int j = n-1;
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }


        //again reverse the first part
        int l = 0;
        int m = k-1;
        while(l<m){
            int temp = nums[l];
            nums[l] = nums[m];
            nums[m] = temp;
            l++;
            m--;
        }

        //again reverse the second part
        int o = k;
        int p = n-1;
        while(o<p){
            int temp = nums[o];
            nums[o] = nums[p];
            nums[p] = temp;
            o++;
            p--;
        }

        return;
    }
};