class Solution {
public:
    int bestClosingTime(string customers) {
        int n= customers.length();
        int pre[n+1]; //calculate N
        int suf[n+1]; //calculate Y
        pre[0] = 0;
        for(int i = 0;i<n;i++){
            int count = 0;
            if(customers[i]=='N') count++;
            pre[i+1]=pre[i]+count;
        }
        suf[n] = 0;
        for(int i = n-1;i>=0;i--){
            int count = 0;
            if(customers[i]=='Y') count++;
            suf[i] = suf[i+1]+count;
        }
        int min = n;
        for(int i = 0;i<=n;i++){
           pre[i]=pre[i]+suf[i];
           if(pre[i]<min){
             min = pre[i];
           }
        }

        for(int i = 0;i<=n;i++){
            if(min==pre[i]) return i;
        }
        return n;
    }
};