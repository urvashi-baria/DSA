class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
          int n = customers.size();
          int firstLossOfSatisfaction = 0;
          for(int i = 0;i<minutes;i++){
            if(grumpy[i]==1){
                firstLossOfSatisfaction+=customers[i];
            }
          }

          int mostLossOfSatisfaction = firstLossOfSatisfaction;
          int startIdx = 0;
          int endIdx = minutes-1;
          int i =1;
          int j = minutes;
          while(j<n){
             if(grumpy[i-1]==1 && grumpy[j]==1){
                firstLossOfSatisfaction = firstLossOfSatisfaction+customers[j]-customers[i-1];
             }
             else if(grumpy[i-1]==0 && grumpy[j]==1){
                firstLossOfSatisfaction = firstLossOfSatisfaction+customers[j];
             }
             else if(grumpy[i-1]==1 && grumpy[j]==0){
                firstLossOfSatisfaction = firstLossOfSatisfaction-customers[i-1];
             }
             else if(grumpy[i-1]==0 && grumpy[j]==0){
                firstLossOfSatisfaction = firstLossOfSatisfaction;
             }

             if(mostLossOfSatisfaction<=firstLossOfSatisfaction){
                mostLossOfSatisfaction=firstLossOfSatisfaction;
                startIdx=i;
                endIdx=j;
             }
             i++;
             j++;
          }

          for(int k=startIdx;k<=endIdx;k++){
              grumpy[k]=0;
          }
          
          int ans = 0;
          for(int k = 0;k<n;k++){
            if(grumpy[k]==0){
                ans+=customers[k];
            }
          }
          return ans;
    }
};