class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st1;
        stack<int> st2;
        vector<int> left(n) , right(n);

        //left min index
        for(int i = 0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st1.top();
            }
            st1.push(i);
        }
 

        for(int i = n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.empty()){
                right[i] = n;
            }
            else{
                right[i] = st2.top();
            }
            st2.push(i);
        }
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            int area = (right[i]-left[i]-1)*heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};