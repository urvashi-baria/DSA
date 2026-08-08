class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(heights[n-1]);
        ans[n-1]=0;
        int count;
        for(int i=n-2;i>=0;i--){
            count = 0;
            while(st.size()!=0 && st.top()<=heights[i]){
               st.pop();
               count++;
            }
            if(st.size()!=0 && st.top()>heights[i]){
                count++;
            }
            st.push(heights[i]);
            ans[i]=count;   
        }
        return ans;
    }
};