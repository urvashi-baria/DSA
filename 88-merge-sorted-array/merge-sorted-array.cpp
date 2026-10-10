
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        if(nums2.size()==0) ans=nums1;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans[k] = nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j]){
                ans[k] = nums2[j];
                j++;
            }
            k++;
        }
        if(i==m){
            while(j<n){
                ans[k]=nums2[j];
                j++;
                k++;
            }
        }
        else if(j==n){
            while(i<m){
                ans[k]=nums1[i];
                i++;
                k++;
            }
        }
        nums1 = ans;
        return;
    }
};






