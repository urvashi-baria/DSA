class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        
        unordered_map<int,int> m;
        m[0]=-1;
        int maxLen = 0;
        int len;
        for(int j = 0;j<n;j++){
            int rem = pref[j]%k;
            if(rem==0){
                len = j-m[rem];
                maxLen = max(maxLen,len);
            }
            if(rem<0){
                rem+=k;
            }
            if(m.find(rem)!=m.end()){
                len = j-m[rem];
                maxLen = max(maxLen,len);
            }
            else {
                m[rem]=j;    
            }
        }
        if(maxLen>=2) return true;
        return false;
    }
};