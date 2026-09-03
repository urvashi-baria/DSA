class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        //4 5 2 1  = nums 3 10 21  = queries
        sort(nums.begin(),nums.end());
        //1 2 4 5 = nums 
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i = 1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        //1 3 7 12
        vector<int> ans(m);
        for(int i = 0;i<m;i++){
            int count=0;
            int low = 0;
            int high = n-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(pref[mid]>queries[i]){
                    high=mid-1;
                }
                else{
                    //pref[mid]<=queries[i]
                    count=mid+1;
                    low = mid+1;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};