class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int> pref(n);
       pref[0]=nums[0];
       for(int i = 1;i<n;i++){
         pref[i]=pref[i-1]+nums[i];
       }

       unordered_map<int,int> m;
       //int = pref;
       //int = frequency of pref
       int count = 0;
       for(int j = 0;j<n;j++){
        if(pref[j]==k) count++;
        int val = pref[j]-k;
        if(m.find(val)!=m.end()){
            count+=m[val];
        }
    
        m[pref[j]]++;
    
       }
       return count;
    }
};