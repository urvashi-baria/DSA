class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        //-1,-8,0,5,-9
        sort(satisfaction.begin(),satisfaction.end());
        //-9,-8,-1,0,5
        vector<int> suff(n);
        suff[n-1]=satisfaction[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i]=suff[i+1]+satisfaction[i];
        }
        //suff=[-13,-4,4,5,5]
        int idx = -1;
        for(int i = 0;i<n;i++){
            if(suff[i]>=0){
                idx=i;
                break;
            }
        }
        //idx = 2
        if(idx==-1){
            return 0;
        }
        else{
            int sum = 0;
            int count = 1;
            for(int i = idx;i<n;i++){
               sum+=satisfaction[i]*count;
               count++;
            }
            return sum;
        }
        return -1;
    }
};