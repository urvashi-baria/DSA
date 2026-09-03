class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        //4 5 2 1  = nums 3 10 21  = queries
        sort(nums.begin(),nums.end());
        //1 2 4 5 = nums 
        vector<int> suff(n);
        suff[0]=nums[0];
        for(int i = 1;i<n;i++){
            suff[i]=suff[i-1]+nums[i];
        }
        //1 3 7 12
        vector<int> ans(m);
        for(int i = 0;i<m;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                if(suff[j]<queries[i]){
                    count++;
                }
                else if(suff[j]==queries[i]){
                    count++;
                    break;
                }
                else{
                    break;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};