class Solution {
    int getRetailers(vector<int>& quantities,int qnt){
        int retail = 0;
        for(int i : quantities){
            retail+=int(ceil(double(i)/qnt));
        }
        return retail;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = 0;
        for(int i: quantities){
              if(i>high){
                high = i;
              }
        }
        
        while(low<=high){
            int mid = (low+high)/2;
            if(getRetailers(quantities,mid)<=n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};