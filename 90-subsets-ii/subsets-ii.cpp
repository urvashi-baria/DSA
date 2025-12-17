class Solution {
public:
    void helper(vector<int> v,vector<int>& nums,vector<vector<int>>& finalAns,int idx,bool flag){
        if(idx==nums.size()){
            finalAns.push_back(v);
            return;
        }
        if(nums.size()==1){
            helper(v,nums,finalAns,idx+1,true);
            v.push_back(nums[idx]);
            helper(v,nums,finalAns,idx+1,true);
        }
        else if(nums.size()>1){
           if(idx<nums.size()-1 && nums[idx]==nums[idx+1] ){
            if(flag==true){helper(v,nums,finalAns,idx+1,true);}
            v.push_back(nums[idx]);
            helper(v,nums,finalAns,idx+1,false);
           }
           else{
            if(flag==true){helper(v,nums,finalAns,idx+1,true);}
            v.push_back(nums[idx]);
            helper(v,nums,finalAns,idx+1,true);
           }
        return;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
              sort(nums.begin(),nums.end());
              vector<vector<int>> finalAns;
              vector<int> v;
              helper(v,nums,finalAns,0,true);
              return finalAns;  
    }
};