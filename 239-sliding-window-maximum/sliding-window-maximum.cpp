class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ngi(size); //next greater element index
        vector<int> ans(size-k+1); // answer vector
        stack<int> st;
        st.push(size-1);
        ngi[size-1] = size-1;
        for(int i = size-2;i>=0;i--){
            while(st.size()!=0 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()!=0){
                ngi[i]=st.top();
            }
            else{
                ngi[i] = i;
            }
            st.push(i);
        }
        
        int j = 0;
        for(int i =0;i<size-k+1;i++){
            if(j<i) j=i;
            int mx = INT_MIN;
            while(j<i+k){
                mx=nums[j];
                if(ngi[j]==j || ngi[j]>=i+k) break;
                j=ngi[j]; 
            }
            ans[i] = mx;
        }
        return ans;
    }
};