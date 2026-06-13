class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map<int,int> m;
        // for(int ele : nums){
        //     m[ele]++;
        // }

        // vector<int> ans;
        // for(auto x: m){
        //     if(x.second==1){
        //         ans.push_back(x.first);
        //     }
        // }
        // return ans;

        long xorr = 0;
        for(int i:nums){
            xorr^=i;
        }
        long b = xorr&-xorr;
        long b1 = 0;
        long b2 =0;

        for(int i : nums){
            if(i&b){
                b1^=i;
            }
            else{
                b2^=i;
            }
        }
        return {(int)b1,(int)b2};
    }
};