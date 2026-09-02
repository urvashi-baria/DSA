class Solution {
public:
    int bestClosingTime(string customers) {
        // int n = customers.length();
        // int minCount = INT_MAX;
        // int ans =-1;
        // int j = 0;
        // while(j<=n){
        //     int count = 0;
        //     for(int i = 0;i<n;i++){
        //         if(i>=j && customers[i]=='Y'){
        //             count++;
        //         }
        //         else if(i<j && customers[i]=='N'){
        //             count++;
        //         }
        //     }
        //     if(count<minCount){
        //         minCount = count;
        //         ans = j;
        //     }
        //     j++;
        // }
        // return ans;

        int n = customers.length();
        int pre[n+1];  //calculate 'N'
        int suf[n+1];  //calculate 'Y'
        pre[0]=0;
        for(int i = 0;i<n;i++){
            pre[i+1]=pre[i]+((customers[i]=='N')?1:0);
        }
        suf[n]=0;
        for(int i = n-1;i>=0;i--){
            suf[i]=suf[i+1]+((customers[i]=='Y')?1:0);
        }
        
        int minCount = INT_MAX;
        for(int i = 0;i<=n;i++){
            pre[i]+=suf[i];
            if(pre[i]<minCount){
               minCount = pre[i];
            }
        }

        for(int i = 0;i<=n;i++){
            if(pre[i]==minCount){
                return i;
            }
        }
        return -1;
    }
};