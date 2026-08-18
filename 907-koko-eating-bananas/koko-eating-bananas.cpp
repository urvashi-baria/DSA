class Solution {
public:
bool chk(int mid,vector<int>& piles,int h){
    int n = piles.size();
    int speed= mid;
    long long count = 0;
    for(int i = 0;i<n;i++){
        if(speed>=piles[i]){
            count++;
        }
        else if(piles[i]%speed==0){
            count+=(long long) piles[i]/speed;
        }  
        else{
            count+=(long long) piles[i]/speed+1;
        }  
    }
    if(count<=h){
        return true;
    }
    return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max=INT_MIN;
        for(int i = 0;i<n;i++){
            if(piles[i]>max){
                max=piles[i];
            }
        }
        int low = 1;
        int high = max;
        int k = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(chk(mid,piles,h)==true){
                k=mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return k;

    }
};