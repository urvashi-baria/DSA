class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i =1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int count=0;
        unordered_map<int,int> m;
        for(int j = 0;j<n;j++){
            int rem = pref[j]%k;
            if(rem==0) count++;
            if(rem<0) rem+=k;

            if(m.find(rem)!=m.end()){
                    count+=m[rem];
            }
       
            m[rem]++;
        }
        return count;
    }
};