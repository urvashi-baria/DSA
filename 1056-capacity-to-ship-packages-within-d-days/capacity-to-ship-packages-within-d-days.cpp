class Solution {
public:
    bool chk(int mid,vector<int>& weights,int days){
        int n = weights.size();
        int capacity = mid;
        int count = 1;
        for(int i = 0;i<n;i++){
            if(capacity>=weights[i]){
                capacity-=weights[i];
            }
            else{
                count++;
                capacity = mid;
                capacity-=weights[i];
            }
        }
        if(count<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxEle = INT_MIN;
        int sum = 0;
        for(int i =0;i<n;i++){
            if(weights[i]>=maxEle){
                maxEle=weights[i];
            }
            sum+=weights[i];
        }
        int low = maxEle;
        int high = sum;
        int minCap = sum;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(chk(mid,weights,days)==true){
                minCap= mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return minCap;
    }
};