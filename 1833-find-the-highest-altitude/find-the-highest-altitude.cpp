class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int totalSum = 0;
        int maxAlt = totalSum;
        for(int i = 0 ;i<n;i++){
            totalSum+=gain[i];
            maxAlt = max(maxAlt,totalSum);
        }
        return maxAlt;
    }
};